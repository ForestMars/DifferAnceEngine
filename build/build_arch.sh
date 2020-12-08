# build_arch.sh - Build script for compiling DAE source code.

# Compile NLU for intent extraction.
# cc -c -o nlu.o nlu.c
# cc nlu.o -shared -o lib/models/nlu.so

# Compile Dialogue model.
# cc -c -o dialog.o dialog.c
#gc dialog.o -shared -o lib/models/dialog.so


gcc -c -fPIC -I/usr/include/python3.8 -o estimators.o estimators.c
gcc -shared -fPIC -I/usr/include/python3.8 -o estimators.so estimators.o

gcc -c -fPIC -I/usr/include/python3.8 -o models.o lib/c/models.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/models.so models.o

gcc -c -fPIC -I/usr/include/python3.8 -o pipes.o lib/c/pipes.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/pipes.so pipes.o

gcc -c -fPIC -I/usr/include/python3.8 -o scoring.o lib/c/scoring.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/scoring.so scoring.o

gcc -c -fPIC -I/usr/include/python3.8 -o trans.o lib/c/trans.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/trans.so trans.o

gcc -c -fPIC -I/usr/include/python3.8 -o tubular.o lib/c/tubular.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/tubular.so tubular.o

gcc -c -fPIC -I/usr/include/python3.8 -o preprocessors.o lib/c/preprocessors.c
gcc -shared -fPIC -I/usr/include/python3.8 -o lib/ext/preprocessors.so preprocessors.o
