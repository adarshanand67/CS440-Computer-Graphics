# Utility to run openGL in VSCODE
file=$1
out=$(basename "$file" ".cpp")
if [ ! -d ".compiled" ] 
then mkdir ".compiled"
fi
export MESA_GL_VERSION_OVERRIDE=4.5 
g++ "$file" -o ".compiled/$out" -lglut -lGLU -lGL -lGLEW 
./".compiled/$out"
