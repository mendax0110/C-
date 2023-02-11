// take the includes from the openssl-3.1.0-beta1 folder
#include <usr/local/opt/openssl/x509.h>
#include <usr/local/opt/openssl/ssl.h>
#include <usr/local/opt/openssl//err.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: x509Check <certfile>\n", argv[0]);
        return 1;
    }

    // Load the certificate file
    BIO* certBio = BIO_new(BIO_s_file());

    if(!BIO_read_filename(certBio, argv[1]))
    {
        printf("Error reading certificate file\n");
        return 1;
    }

    // Load the certificate into an X509 structure
    X509* cert = PEM_read_bio_X509(certBio, NULL, 0, NULL);

    if(!cert)
    {
        printf("Error loading certificate into memory\n");
        return 1;
    }

    // INitialize the OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Check the validity of the certificate
    X509_STORE* store = X509_STORE_new();
    X509_STORE_CTX* ctx = X509_STORE_CTX_new();

    if(!X509_STORE_CTX_init(ctx, store, cert, NULL))
    {
        printf("Error initializing X509_STORE_CTX\n");
        return 1;
    }

    int ret = X509_verify_cert(ctx);
    X509_STORE_CTX_free(ctx);
    X509_STORE_free(store);
    X509_free(cert);
    BIO_free(certBio);

    if(result == 1)
    {
        printf("Certificate is valid\n");
        return 0;
    }
    else
    {
        printf("Certificate is invalid\n");
        return 1;
    }
}
