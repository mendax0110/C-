#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Initialize the library
    OenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    ERR_load_BIO_strings();

    // Create a new RSA key pair
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);

    // Create a new X509 certificate
    X509 *cert = X509_new();
    X509_set_version(cert, 2);
    ASN1_INTEGER_set(X509_get_serialNumber(cert), 0);
    X509_gmtime_adj(X509_get_notBefore(cert), 0);
    X509_gmtime_adj(X509_get_notAfter(cert), 60 * 60 * 24 * 365);
    X509_set_pubkey(cert, EVP_PKEY_new());
    X509_sign(cert, EVP_PKEY_new(), EVP_sha256());

    // Write the certificate to a file
    BIO *bio = BIO_new_file("cert.pem", "w");
    PEM_write_bio_X509(bio, cert);
    BIO_free_all(bio);

    // Free the memory
    X509_free(cert);
    RSA_free(rsa);

    return 0;
}