import os
import subprocess
import platform

from setup_premake import PremakeConfiguration as PremakeRequirements
os.chdir('./../') # change directory to /project/

detectedOs = platform.system()

premakeInstalled = PremakeRequirements.Validate()

print("\nUpdating submodules...")
subprocess.call(["git", "submodule", "update", "--init", "--recursive"])

if (premakeInstalled):
    print("\nRunning premake...")
    if detectedOs == "Windows":
        print(f"Current Path: " + os.path.abspath("./setup"))
        subprocess.call([os.path.abspath("./setup/run-premake.bat"), "nopause"])
    elif detectedOs == "Darwin" or detectedOs == "Linux":
        subprocess.call([os.path.abspath("./setup/run-premake.sh"), "nopause"])
        
    print("\nSetup completed!")
else:
    print("This project requires Premake to generate project files. Please install Premake to continue!")