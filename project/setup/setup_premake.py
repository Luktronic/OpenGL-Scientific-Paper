import sys
import os
import platform
from pathlib import Path

import utils

class PremakeConfiguration:
    premakeVersion = "5.0.0-beta2"
    premakeWindowsName = f"premake-{premakeVersion}-windows.zip"
    premakeLinuxName = f"premake-{premakeVersion}-linux.tar.gz"
    premakeMacName = f"premake-{premakeVersion}-macosx.tar.gz"
    premakeDownloadUrl = f"https://github.com/premake/premake-core/releases/download/v{premakeVersion}/"
    premakeLicenseUrl = "https://raw.githubusercontent.com/premake/premake-core/master/LICENSE.txt"
    premakeDirectory = "./vendor/bin/premake"

    @classmethod
    def Validate(cls):
        if (not cls.CheckIfPremakeInstalled()):
            print("Premake is not installed.")
            return False

        print(f"Correct Premake located at {os.path.abspath(cls.premakeDirectory)}")
        return True

    @classmethod
    def CheckIfPremakeInstalled(cls):
        premakeExe = Path(f"{cls.premakeDirectory}/premake5.exe");
        if (not premakeExe.exists()):
            return cls.InstallPremake()

        return True

    @classmethod
    def InstallPremake(cls):
        permissionGranted = False
        while not permissionGranted:
            reply = str(input("No installation of premake found. Would you like to download Premake {0:s}? [y/n]: ".format(cls.premakeVersion))).lower().strip()[:1]
            if reply == 'n':
                return False
            permissionGranted = (reply == 'y')

        detectedOs = platform.system()
        print(f"Detected Operating System: {detectedOs}")
        if detectedOs == "Windows":
            cls.premakeDownloadUrl = f"{cls.premakeDownloadUrl}{cls.premakeWindowsName}"
            premakePath = f"{cls.premakeDirectory}/{cls.premakeWindowsName}"
        elif detectedOs == "Linux":
            cls.premakeDownloadUrl = f"{cls.premakeDownloadUrl}{cls.premakeLinuxName}"
            premakePath = f"{cls.premakeDirectory}/{cls.premakeLinuxName}"
        elif detectedOs == "Darwin":
            cls.premakeDownloadUrl = f"{cls.premakeDownloadUrl}{cls.premakeMacName}"
            premakePath = f"{cls.premakeDirectory}/{cls.premakeMacName}"

        print("Downloading {0:s} to {1:s}".format(cls.premakeDownloadUrl, premakePath))
        utils.DownloadFile(cls.premakeDownloadUrl, premakePath)
        print("Extracting", premakePath)
        utils.UnzipFile(premakePath, deleteZipFile=True)
        print(f"Premake version {cls.premakeVersion} was successfully downloaded to path '{cls.premakeDirectory}'")

        premakeLicensePath = f"{cls.premakeDirectory}/LICENSE.txt"
        print("Downloading {0:s} to {1:s}".format(cls.premakeLicenseUrl, premakeLicensePath))
        utils.DownloadFile(cls.premakeLicenseUrl, premakeLicensePath)
        print(f"Premake License file was successfully downloaded to '{cls.premakeDirectory}'")

        return True