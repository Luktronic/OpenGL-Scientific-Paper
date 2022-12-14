#!/bin/bash
echo "Starting build..."
set -e # Fail if command fails

tmp_path='/tmp/pre-build'

mkdir -p $tmp_path

cp -r . $tmp_path/

cd $tmp_path/paper

# Add path to allow imports
export PYTHONPATH=$PYTHONPATH:$(pwd)/writing/diagrams

echo "Building PDF version..."
asciidoctor-pdf \
-r /tmp/asciidoctor-diagram/lib/asciidoctor-diagram.rb \
-r asciidoctor-mathematical \
-r asciidoctor-bibtex \
-r asciidoctor-lists \
-o OpenGL-Scientific-Paper.pdf \
writing/main.adoc # --trace -v -w -t

cp OpenGL-Scientific-Paper.pdf /work/paper/build/

echo "Building printed version..."
asciidoctor-pdf \
-r /tmp/asciidoctor-diagram/lib/asciidoctor-diagram.rb \
-r asciidoctor-mathematical \
-r asciidoctor-bibtex \
-r asciidoctor-lists \
-o OpenGL-Scientific-Paper-printed.pdf \
-a printed-version=true \
writing/main.adoc # --trace -v -w -t

cp OpenGL-Scientific-Paper-printed.pdf /work/paper/build/

rm -rf $tmp_path
