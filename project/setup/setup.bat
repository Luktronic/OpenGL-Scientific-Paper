@echo off
CD .\setup
echo Installing Python requests module...
python -m pip install requests
python .\setup.py
PAUSE