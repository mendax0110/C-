#include <iostream>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/x509_vfy.h>

int main()
{
    // Load the certificate
    X509 *cert = NULL;
    FILE *fp = fopen("cert.pem", "r");

    if (fp == NULL)
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    cert = PEM_read_X509(fp, NULL, NULL, NULL);
    fclose(fp);

    if (cert == NULL)
    {
        std::cout << "Error reading certificate" << std::endl;
        return 1;
    }

    // Change the CN name
    X509_NAME *name = X509_get_subject_name(cert);

    if (name == NULL)
    {
        std::cout << "Error getting subject name" << std::endl;
        x509_free(cert);
        return 1;
    }

    int pos = X509_NAME_get_index_by_NID(name, NID_commonName, -1);

    if(pos == -1)
    {
        std::cout << "Error getting CN index" << std::endl;
        x509_free(cert);
        return 1;
    }

    X509_NAME_ENTRY *entry = X509_NAME_get_entry(name, pos);
    ASN1_STRING *data = X509_NAME_ENTRY_get_data(entry);

    usigned char *newCN = (unsigned char *)"New CN";
    int len = strlen((char *)newCN);

    std::string oldCN = (char *)ASN1_STRING_data(data);

    ASN1_STRING_set(value, (unsigned char *)newCN, len);

    // Save the updated certificate
    fp = fopen("cert.pem", "w");

    if (fp == NULL)
    {
        std::cout << "Error opening file" << std::endl;
        x509_free(cert);
        return 1;
    }

    int res = PEM_read_bio_X509(fp, cert, NULL, NULL);
    fclose(fp);

    if (res == 0)
    {
        std::cout << "Error writing certificate" << std::endl;
        x509_free(cert);
        return 1;
    }

    // cleanup
    x509_free(cert);

    return 0;
}