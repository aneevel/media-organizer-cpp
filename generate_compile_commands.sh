#!/bin/bash
# save as generate_compile_commands.sh

echo "[" >compile_commands.json
echo "  {" >>compile_commands.json
echo "    \"directory\": \"$(pwd)\"," >>compile_commands.json
echo "    \"command\": \"clang++ -c main.cpp $(pkg-config --cflags gtkmm-4.0)\"," >>compile_commands.json
echo "    \"file\": \"$(pwd)/main.cpp\"" >>compile_commands.json
echo "  }" >>compile_commands.json
echo "]" >>compile_commands.json

chmod +x generate_compile_commands.sh
