---


---

<h1 id="fract-ol">Fract-ol</h1>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/fractol-01.jpg" alt="fractol"></p>
<div align="center">
<p></p><h3>Fract-ol is a graphic fractal exploration program, supporting deep-zooms.
<p></p></h3><h5>MacOs support only
</h5><p></p><p></p></div>
<h2 id="general">General</h2>
<p>Fract-ol runs it’s calculations on <strong>OpenCL</strong>, which allows for a high iteration count renders and smooth deep-zoom experience.</p>
<p>This project makes use of my <a href="https://github.com/DippyArtu/libcl">libcl</a> library, to make it easier to work with OpenCL and a <a href="https://github.com/DippyArtu/complex_opencl">complex_opencl</a> library, which allows to perform arythmetics on complex numbers inside the cl kernel.</p>
<h2 id="fractals">Fractals</h2>
<h3 id="mandelbrot-set">Mandelbrot Set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/iterpow.png" alt="iterpow"></p>
<div align="center">
<img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/mand.jpg">
</div>
<h3 id="julia-sets">Julia sets</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/julia.jpg" alt="julia"></p>
<div align="center">
<img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/jul%20equ.jpg">
</div>
<h3 id="burning-ship-set">Burning Ship set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/ship.jpg" alt="ship"></p>
<div align="center">
<img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/ship%20equ.jpg">
</div>
<h3 id="buddhabrot-set">Buddhabrot set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/buddha2.png" alt="buddha"></p>
<div align="center">
<img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/buddha%20equ.jpg">
</div>
<h2 id="coloring-models">Coloring models</h2>
<h3 id="iteration-based-count">Iteration-based count</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/iter.png" alt="iter"></p>
<h3 id="escape-time-potential">Escape-time potential</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/iterpow.png" alt="iterpow"></p>
<h3 id="log-potential-smoothstep">Log-potential (smoothstep)</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/smooth.png" alt="smooth"></p>
<h3 id="black-and-white-log-potential-smoothstep">Black and white log-potential (smoothstep)</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/bw.png" alt="bw"></p>
<h3 id="normal-map-effect">Normal-map effect</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/normal.png" alt="normal"></p>
<h2 id="usage">Usage</h2>
<p>Place the directory in your <strong>root</strong> folder and compile it with</p>
<pre><code>make
</code></pre>
<p>Run the program with</p>
<pre><code>./fractol *type_of_fractal*
</code></pre>
<p>Where <code>*type_of_fractal*</code> can be one of the following:</p>
<ul>
<li>Mandelbrot</li>
<li>Julia</li>
<li>Burning_ship</li>
<li>Buddhabrot</li>
<li>Buddhabrot_precalc</li>
</ul>
<p>There are 2 types of Buddhabrot fractals available – normal one, and precalculated one. Because Buddhabrot set is a very computationally intensive task, calculating the set can take a while. For this reason, the precalculated version is available. It will read the data from the map “save” file, <code>buddha_map</code>, and display it on the screen.</p>
<p>Apart from all the normal functionale, it is also possible to change the direction of light falling onto the set in the <em>color mode 5</em>.<br>
<em>This mode is available for Mandelbrot and Julia fractals only.</em></p>

