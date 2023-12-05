autoreconf -fisv
./configure
make

make run_en    (or ./guess)
make run_ru    (or LANGUAGE=ru_RU.UTF8 ./guess)

make clean
