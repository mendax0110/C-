#include <iostream>
#include <fstream>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

// base64 decode a file
int main(int argc, char* argv[])
{
    // check the command line arguments
    if(argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input file> <output file>" << std::endl;
        return 1;
    }

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];

    // open the input file
    std::ifstream inputFile(inputFileName, std::ios::binary);

    if(!ifs)
    {
        std::cerr << "Error: Could not open input file " << inputFileName << std::endl;
        return 1;
    }

    // read the base64 encoded data form the input file
    std::string base64Data((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // create a BIO filter to decode the base64 data
    BIO* b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    // create a memory buffer to hold the decoded data
    BIO* mem = BIO_new(BIO_s_mem());

    // create a bio chain to perform the decoding
    BIO* chain = BIO_push(b64, bmem);
    BIO_write(chain, base64Data.c_str(), base64Data.length());
    BIO_flush(chain);

    // get the decoded data from the memory buffer
    BUF_MEM* bptr;
    BIO_get_mem_ptr(chain, &bptr);

    // write the decoded data to the output file
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if(!ofs)
    {
        std::cerr << "Error: Could not open output file " << outputFileName << std::endl;
        return 1;
    }

    ofs.write(bptr->data, bptr->length);

    // free the bio chain
    BIO_free_all(chain);

    return 0;
}

