# Fract-ol
![fractol](https://github.com/DippyArtu/Fract-ol/blob/master/pics/fractol-01.jpg)

Fract-ol is a graphic fractal exploration program, supporting deep-zooms.

**MacOs support only**

## General

Fract-ol runs it's calculations on **OpenCL**, which allows for a high iteration count renders and smooth deep-zoom experience.

This project makes use of my [libcl](https://github.com/DippyArtu/libcl) library, to make it easier to work with OpenCL and a [complex_opencl](https://github.com/DippyArtu/complex_opencl) library, which allows to perform arythmetics on complex numbers inside the cl kernel.

## Fractals

### Mandelbrot Set
![iterpow](https://github.com/DippyArtu/Fract-ol/blob/master/pics/iterpow.png)

$$
Z_{n + 1} = Z_{n}^2 + c
$$

$$
Z_0 = 0
$$

$$
c = x+yi
$$

### Julia sets
![julia](https://github.com/DippyArtu/Fract-ol/blob/master/pics/julia.jpg)

$$
Z_{n + 1} = Z_{n}^2 + k
$$

$$
Z_0 = x+yi
$$

$$
k = c
$$

$$
[c > (-2+-2i) ; c < (2+2i)]
$$

### Burning Ship set
![ship](https://github.com/DippyArtu/Fract-ol/blob/master/pics/ship.jpg)

$$
Z_{n + 1} = (|Re(Z_n)| + i|Im(Z_n)|)^2 + c
$$

$$
Z_0 = 0
$$

$$
c = x+yi
$$

### Buddhabrot set
![buddha](https://github.com/DippyArtu/Fract-ol/blob/master/pics/buddha2.png)

$$
Z_{n + 1} = Z_{n}^2 + c
$$

$$
Z_0 = 0
$$

$$
c = rand(c)
$$

$$
[c > (-2+-2i) ; c < (2+2i)]
$$

## Coloring models

### Iteration-based count
![iter](https://github.com/DippyArtu/Fract-ol/blob/master/pics/iter.png)

### Escape-time potential
![iterpow](https://github.com/DippyArtu/Fract-ol/blob/master/pics/iterpow.png)

### Log-potential (smoothstep)
![smooth](https://github.com/DippyArtu/Fract-ol/blob/master/pics/smooth.png)

### Black and white log-potential (smoothstep)
![bw](https://github.com/DippyArtu/Fract-ol/blob/master/pics/bw.png)

### Normal-map effect
![normal](https://github.com/DippyArtu/Fract-ol/blob/master/pics/normal.png)

## Usage

Place the directory in your **root** folder and compile it with

	make

Run the program with

	./fractol *type_of_fractal*

Where `*type_of_fractal*` can be one of the following:

 - Mandelbrot
 - Julia
 - Burning_ship
 - Buddhabrot
 - Buddhabrot_precalc

There are 2 types of Buddhabrot fractals available – normal one, and precalculated one. Because Buddhabrot set is a very computationally intensive task, calculating the set can take a while. For this reason, the precalculated version is available. It will read the data from the map "save" file, `buddha_map`, and display it on the screen.

Apart from all the normal functionale, it is also possible to change the direction of light falling onto the set in the *color mode 5*.
*This mode is available for Mandelbrot and Julia fractals only.*

