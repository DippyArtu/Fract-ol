---


---

<h1 id="fract-ol">Fract-ol</h1>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/fractol-01.jpg" alt="fractol"></p>
<p>Fract-ol is a graphic fractal exploration program, supporting deep-zooms.</p>
<p><strong>MacOs support only</strong></p>
<h2 id="general">General</h2>
<p>Fract-ol runs it’s calculations on <strong>OpenCL</strong>, which allows for a high iteration count renders and smooth deep-zoom experience.</p>
<p>This project makes use of my <a href="https://github.com/DippyArtu/libcl">libcl</a> library, to make it easier to work with OpenCL and a <a href="https://github.com/DippyArtu/complex_opencl">complex_opencl</a> library, which allows to perform arythmetics on complex numbers inside the cl kernel.</p>
<h2 id="fractals">Fractals</h2>
<h3 id="mandelbrot-set">Mandelbrot Set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/iterpow.png" alt="iterpow"></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mrow><mi>n</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>=</mo><msubsup><mi>Z</mi><mi>n</mi><mn>2</mn></msubsup><mo>+</mo><mi>c</mi></mrow><annotation encoding="application/x-tex">
Z_{n + 1} = Z_{n}^2 + c
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.891661em; vertical-align: -0.208331em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.301108em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span><span class="mbin mtight">+</span><span class="mord mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.208331em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1.1111079999999998em; vertical-align: -0.247em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.8641079999999999em;"><span class="" style="top: -2.4530000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span></span></span></span><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.247em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mn>0</mn></msub><mo>=</mo><mn>0</mn></mrow><annotation encoding="application/x-tex">
Z_0 = 0
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83333em; vertical-align: -0.15em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.30110799999999993em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">0</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">0</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>c</mi><mo>=</mo><mi>x</mi><mo>+</mo><mi>y</mi><mi>i</mi></mrow><annotation encoding="application/x-tex">
c = x+yi
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.66666em; vertical-align: -0.08333em;"></span><span class="mord mathdefault">x</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.85396em; vertical-align: -0.19444em;"></span><span class="mord mathdefault" style="margin-right: 0.03588em;">y</span><span class="mord mathdefault">i</span></span></span></span></span></span></p>
<h3 id="julia-sets">Julia sets</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/julia.jpg" alt="julia"></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mrow><mi>n</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>=</mo><msubsup><mi>Z</mi><mi>n</mi><mn>2</mn></msubsup><mo>+</mo><mi>k</mi></mrow><annotation encoding="application/x-tex">
Z_{n + 1} = Z_{n}^2 + k
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.891661em; vertical-align: -0.208331em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.301108em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span><span class="mbin mtight">+</span><span class="mord mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.208331em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1.1111079999999998em; vertical-align: -0.247em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.8641079999999999em;"><span class="" style="top: -2.4530000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span></span></span></span><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.247em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.69444em; vertical-align: 0em;"></span><span class="mord mathdefault" style="margin-right: 0.03148em;">k</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mn>0</mn></msub><mo>=</mo><mi>x</mi><mo>+</mo><mi>y</mi><mi>i</mi></mrow><annotation encoding="application/x-tex">
Z_0 = x+yi
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83333em; vertical-align: -0.15em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.30110799999999993em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">0</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.66666em; vertical-align: -0.08333em;"></span><span class="mord mathdefault">x</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.85396em; vertical-align: -0.19444em;"></span><span class="mord mathdefault" style="margin-right: 0.03588em;">y</span><span class="mord mathdefault">i</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>k</mi><mo>=</mo><mi>c</mi></mrow><annotation encoding="application/x-tex">
k = c
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.69444em; vertical-align: 0em;"></span><span class="mord mathdefault" style="margin-right: 0.03148em;">k</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mo stretchy="false">[</mo><mi>c</mi><mo>&gt;</mo><mo stretchy="false">(</mo><mo>−</mo><mn>2</mn><mo>+</mo><mo>−</mo><mn>2</mn><mi>i</mi><mo stretchy="false">)</mo><mo separator="true">;</mo><mi>c</mi><mo>&lt;</mo><mo stretchy="false">(</mo><mn>2</mn><mo>+</mo><mn>2</mn><mi>i</mi><mo stretchy="false">)</mo><mo stretchy="false">]</mo></mrow><annotation encoding="application/x-tex">
[c &gt; (-2+-2i) ; c &lt; (2+2i)]
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">[</span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">&gt;</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">−</span><span class="mord">2</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord">−</span><span class="mord">2</span><span class="mord mathdefault">i</span><span class="mclose">)</span><span class="mpunct">;</span><span class="mspace" style="margin-right: 0.16666666666666666em;"></span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">&lt;</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">2</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord">2</span><span class="mord mathdefault">i</span><span class="mclose">)</span><span class="mclose">]</span></span></span></span></span></span></p>
<h3 id="burning-ship-set">Burning Ship set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/ship.jpg" alt="ship"></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mrow><mi>n</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>=</mo><mo stretchy="false">(</mo><mi mathvariant="normal">∣</mi><mi>R</mi><mi>e</mi><mo stretchy="false">(</mo><msub><mi>Z</mi><mi>n</mi></msub><mo stretchy="false">)</mo><mi mathvariant="normal">∣</mi><mo>+</mo><mi>i</mi><mi mathvariant="normal">∣</mi><mi>I</mi><mi>m</mi><mo stretchy="false">(</mo><msub><mi>Z</mi><mi>n</mi></msub><mo stretchy="false">)</mo><mi mathvariant="normal">∣</mi><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mi>c</mi></mrow><annotation encoding="application/x-tex">
Z_{n + 1} = (|Re(Z_n)| + i|Im(Z_n)|)^2 + c
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.891661em; vertical-align: -0.208331em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.301108em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span><span class="mbin mtight">+</span><span class="mord mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.208331em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">∣</span><span class="mord mathdefault" style="margin-right: 0.00773em;">R</span><span class="mord mathdefault">e</span><span class="mopen">(</span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.151392em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathdefault mtight">n</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mclose">)</span><span class="mord">∣</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 1.1141079999999999em; vertical-align: -0.25em;"></span><span class="mord mathdefault">i</span><span class="mord">∣</span><span class="mord mathdefault" style="margin-right: 0.07847em;">I</span><span class="mord mathdefault">m</span><span class="mopen">(</span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.151392em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathdefault mtight">n</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mclose">)</span><span class="mord">∣</span><span class="mclose"><span class="mclose">)</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.8641079999999999em;"><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mn>0</mn></msub><mo>=</mo><mn>0</mn></mrow><annotation encoding="application/x-tex">
Z_0 = 0
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83333em; vertical-align: -0.15em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.30110799999999993em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">0</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">0</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>c</mi><mo>=</mo><mi>x</mi><mo>+</mo><mi>y</mi><mi>i</mi></mrow><annotation encoding="application/x-tex">
c = x+yi
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.66666em; vertical-align: -0.08333em;"></span><span class="mord mathdefault">x</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.85396em; vertical-align: -0.19444em;"></span><span class="mord mathdefault" style="margin-right: 0.03588em;">y</span><span class="mord mathdefault">i</span></span></span></span></span></span></p>
<h3 id="buddhabrot-set">Buddhabrot set</h3>
<p><img src="https://github.com/DippyArtu/Fract-ol/blob/master/pics/buddha2.png" alt="buddha"></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mrow><mi>n</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>=</mo><msubsup><mi>Z</mi><mi>n</mi><mn>2</mn></msubsup><mo>+</mo><mi>c</mi></mrow><annotation encoding="application/x-tex">
Z_{n + 1} = Z_{n}^2 + c
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.891661em; vertical-align: -0.208331em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.301108em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span><span class="mbin mtight">+</span><span class="mord mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.208331em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1.1111079999999998em; vertical-align: -0.247em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.8641079999999999em;"><span class="" style="top: -2.4530000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathdefault mtight">n</span></span></span></span><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.247em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><msub><mi>Z</mi><mn>0</mn></msub><mo>=</mo><mn>0</mn></mrow><annotation encoding="application/x-tex">
Z_0 = 0
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83333em; vertical-align: -0.15em;"></span><span class="mord"><span class="mord mathdefault" style="margin-right: 0.07153em;">Z</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.30110799999999993em;"><span class="" style="top: -2.5500000000000003em; margin-left: -0.07153em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">0</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.15em;"><span class=""></span></span></span></span></span></span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">0</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>c</mi><mo>=</mo><mi>r</mi><mi>a</mi><mi>n</mi><mi>d</mi><mo stretchy="false">(</mo><mi>c</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">
c = rand(c)
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathdefault" style="margin-right: 0.02778em;">r</span><span class="mord mathdefault">a</span><span class="mord mathdefault">n</span><span class="mord mathdefault">d</span><span class="mopen">(</span><span class="mord mathdefault">c</span><span class="mclose">)</span></span></span></span></span></span></p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mo stretchy="false">[</mo><mi>c</mi><mo>&gt;</mo><mo stretchy="false">(</mo><mo>−</mo><mn>2</mn><mo>+</mo><mo>−</mo><mn>2</mn><mi>i</mi><mo stretchy="false">)</mo><mo separator="true">;</mo><mi>c</mi><mo>&lt;</mo><mo stretchy="false">(</mo><mn>2</mn><mo>+</mo><mn>2</mn><mi>i</mi><mo stretchy="false">)</mo><mo stretchy="false">]</mo></mrow><annotation encoding="application/x-tex">
[c &gt; (-2+-2i) ; c &lt; (2+2i)]
</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">[</span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">&gt;</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">−</span><span class="mord">2</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord">−</span><span class="mord">2</span><span class="mord mathdefault">i</span><span class="mclose">)</span><span class="mpunct">;</span><span class="mspace" style="margin-right: 0.16666666666666666em;"></span><span class="mord mathdefault">c</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span><span class="mrel">&lt;</span><span class="mspace" style="margin-right: 0.2777777777777778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">2</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222222222222222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord">2</span><span class="mord mathdefault">i</span><span class="mclose">)</span><span class="mclose">]</span></span></span></span></span></span></p>
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

