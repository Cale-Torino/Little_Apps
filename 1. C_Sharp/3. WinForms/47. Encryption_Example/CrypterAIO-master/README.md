# crypterAIO
Basic end-to-end encryption in C#

# Features:
 * Single-string encryption & decryption.
 * Mass-string encryption & decryption (for if you have multiple lines you'd like to have encrypted seperately, but don't want to manually encrypt them one-by-one.
 * QR-code encryption & decryption.

# How it works:
You simply enter any string that you would like to be encrypted, enter in a password/secret key for the specific context so both ends can decrypt the string afterwards.
The string will come out encrypted afterwards, where you can then send it to the recipient.
A basic demo on how encrypted chat COULD work.

# Encryption algorithm:
Using the RijndaelManaged Class in Visual Studio, you can use an algorithm, which can encrypt any string.
The kind of algorithm you use for end-to-end encryption should vary depending on how secure it must be for that specific case.
For reference: https://docs.microsoft.com/da-dk/dotnet/api/system.security.cryptography.rijndaelmanaged?view=netframework-4.8

# Screenshots:
**SingleEncryption**

![SingleEncryption](https://i.imgur.com/uwVHpls.png)

**SingleDecryption**

![SingleDecryption](https://i.imgur.com/OXuqRro.png)

**QR Encryption**

![QREncryption](https://i.imgur.com/1WoEfae.png)

**QR Decryption**

![QRDecryption](https://i.imgur.com/2VOmXJR.png)
