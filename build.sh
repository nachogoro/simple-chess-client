pushd ../simple-chess-games
./build.sh
popd
mkdir -p libs/simple-chess-games/bin/
cp ../simple-chess-games/build/libsimple-chess-games-static.a libs/simple-chess-games/bin/libsimple-chess-games.a
cp -R ../simple-chess-games/include libs/simple-chess-games

cmake -S . -B build && cmake --build build
