
h1 DEPLOY QT APP FOR WINDOWS

# 1. Requirements

- Build the code generating .exe file
- Download windployqt binary. Usually is located in Qt/15.5.2/MinGW/bin

# 2. Deploy app

- Go to folder in which .exe is located 
- Copy windeployqt.exe in this path or modify Windows PATH to find windeployqt.exe
- Run command 

        windeployqt.exe file.exe
- Copy al files and folders generated in another location (bin/) with the file.exe
- Zip this folder

# 3. Problems

## 3.1 Error 0x000007B

This errors occurs because windeployqt get all .dll needed by the app from you computer looking for in the folders added in PATH environment variable. It is possible that windeploy finds a 32 bits library but the app needs 64 bits library. 

To solve this issue go to Qt/15.5.2/MinGW/ and copy this common libraries in the bin/ folder

libwinpthread-1
libgcc_s_seh-1
libstdc++-6

## 3.2 Libraries not found

Windeployqt in some case does not find all libraries. 
To solve this issue look for and copy the libraries requiered in the bin/ folder. Usually, this libraries are located in Qt/15.5.2/MinGW

## 3.3 qrc:main.qml:-1 Not found

To this issue go to Windows Environment Variable and check ii Path variable there is a reference to Qt/15.5.2/MinGW/bin with a diferent version than the ones is referenced in CmakeList.txt.