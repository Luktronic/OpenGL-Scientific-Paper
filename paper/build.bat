@echo off
echo Preparing build...
if exist build rmdir /Q /S build

echo Building asciidoc-to-pdf docker container...
docker build -f asciidoc-to-pdf.Dockerfile -t thesis-ascii-to-pdf . || goto :error

mkdir build

echo Running asciidoc-to-pdf docker container...
docker run --rm -v "%cd%/writing:/work/paper/writing" -v "%cd%/../project/OpenGLPaper/src:/work/project/OpenGLPaper/src" -v "%cd%/assets:/work/paper/assets" -v "%cd%/build:/work/paper/build" thesis-ascii-to-pdf || goto :error

echo Build done!

goto :EOF

:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%