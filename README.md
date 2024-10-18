# Image_encryption_program
This is an image encryption program written in C. A password and an image are passed to it through the command line, and an encrypted image is outputted (The original Image is not overwritten or altered). The image can be decrypted by passing the same password and encrypted image back to the program.

Before using it, make sure that the name of the image is below 10 characters and that the A2 file and the image are in the same directory.

#How To Use
1. Using the terminal, navigate to the executable file.
2. In the terminal, run this command "./A2 "Name of the image" "password used for encrypting the image."

If done correctly, a new image with the prefix ("new-" + image name) will be outputted in the directory the code was executed in.
