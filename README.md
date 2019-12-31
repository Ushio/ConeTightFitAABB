## Cone TightFit AABB

Thanks 
http://iquilezles.org/www/articles/diskbbox/diskbbox.htm

```

git submodule update --init
premake5 vs2019

```

## demo
![image](demo.gif)
![image](idea.png)
![image](form.png)

<!-- 
a=\begin{pmatrix} x_{ T } \\ y_{ T } \\ z_{ T } \end{pmatrix}=P_{ 1 }-P_{ 0 }\\ \overrightarrow { x } =\begin{pmatrix} 1 \\ 0 \\ 0 \end{pmatrix},\overrightarrow { y } =\begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix},\overrightarrow { z } =\begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix}\\ \overrightarrow { x } \times a=\begin{pmatrix} y_{ 1 }z_{ 2 }-z_{ 1 }y_{ 2 } \\ z_{ 1 }x_{ 2 }-x_{ 1 }z_{ 2 } \\ x_{ 1 }y_{ 2 }-y_{ 1 }x_{ 2 } \end{pmatrix}=\begin{pmatrix} 0z_{ 2 }-0y_{ 2 } \\ 0x_{ 2 }-1z_{ 2 } \\ 1y_{ 2 }-0x_{ 2 } \end{pmatrix}=\begin{pmatrix} 0 \\ -z_{ T } \\ y_{ T } \end{pmatrix}\\ \left\| \overrightarrow { x } \times a \right\| =\sqrt { { z_{ T } }^{ 2 }+{ y_{ T } }^{ 2 } } \\ \left\| \overrightarrow { x } \times \frac { a }{ \left\| a \right\|  }  \right\| =\frac { 1 }{ \left\| a \right\|  } \sqrt { { z_{ T } }^{ 2 }+{ y_{ T } }^{ 2 } } =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { z_{ T } }^{ 2 }+{ y_{ T } }^{ 2 } \right)  } \\ \\ { x_{ T } }^{ 2 }+{ y_{ T } }^{ 2 }+{ z_{ T } }^{ 2 }={ \left\| a \right\|  }^{ 2 }\\ { y_{ T } }^{ 2 }+{ z_{ T } }^{ 2 }={ \left\| a \right\|  }^{ 2 }-{ x_{ T } }^{ 2 }\\ \left\| \overrightarrow { x } \times \frac { a }{ \left\| a \right\|  }  \right\| =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { \left\| a \right\|  }^{ 2 }-{ x_{ T } }^{ 2 } \right)  } =\sqrt { 1-\frac { { x_{ T } }^{ 2 } }{ { \left\| a \right\|  }^{ 2 } }  } \\ \\ \overrightarrow { y } \times a=\begin{pmatrix} y_{ 1 }z_{ 2 }-z_{ 1 }y_{ 2 } \\ z_{ 1 }x_{ 2 }-x_{ 1 }z_{ 2 } \\ x_{ 1 }y_{ 2 }-y_{ 1 }x_{ 2 } \end{pmatrix}=\begin{pmatrix} 1z_{ 2 }-0y_{ 2 } \\ 0x_{ 2 }-0z_{ 2 } \\ 0y_{ 2 }-1x_{ 2 } \end{pmatrix}=\begin{pmatrix} z_{ T } \\ 0 \\ -x_{ T } \end{pmatrix}\\ \left\| \overrightarrow { y } \times a \right\| =\sqrt { { z_{ T } }^{ 2 }+{ x_{ T } }^{ 2 } } \\ \left\| \overrightarrow { y } \times \frac { a }{ \left\| a \right\|  }  \right\| =\frac { 1 }{ \left\| a \right\|  } \sqrt { { z_{ T } }^{ 2 }+{ x_{ T } }^{ 2 } } =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { z_{ T } }^{ 2 }+{ x_{ T } }^{ 2 } \right)  } \\ =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { \left\| a \right\|  }^{ 2 }-{ y_{ T } }^{ 2 } \right)  } =\sqrt { 1-\frac { { y_{ T } }^{ 2 } }{ { \left\| a \right\|  }^{ 2 } }  } \\ \\ \overrightarrow { z } \times a=\begin{pmatrix} y_{ 1 }z_{ 2 }-z_{ 1 }y_{ 2 } \\ z_{ 1 }x_{ 2 }-x_{ 1 }z_{ 2 } \\ x_{ 1 }y_{ 2 }-y_{ 1 }x_{ 2 } \end{pmatrix}=\begin{pmatrix} 0z_{ 2 }-1y_{ 2 } \\ 1x_{ 2 }-0z_{ 2 } \\ 0y_{ 2 }-0x_{ 2 } \end{pmatrix}=\begin{pmatrix} -y_{ T } \\ x_{ T } \\ 0 \end{pmatrix}\\ \left\| \overrightarrow { z } \times \frac { a }{ \left\| a \right\|  }  \right\| =\frac { 1 }{ \left\| a \right\|  } \sqrt { { x_{ T } }^{ 2 }+{ y_{ T } }^{ 2 } } =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { x_{ T } }^{ 2 }+{ y_{ T } }^{ 2 } \right)  } \\ =\sqrt { \frac { 1 }{ { \left\| a \right\|  }^{ 2 } } \left( { \left\| a \right\|  }^{ 2 }-{ z_{ T } }^{ 2 } \right)  } =\sqrt { 1-\frac { { z_{ T } }^{ 2 } }{ { \left\| a \right\|  }^{ 2 } }  } \\ \overrightarrow { e } =\begin{pmatrix} \sqrt { 1-\frac { { x_{ T } }^{ 2 } }{ a\cdot a }  }  \\ \sqrt { 1-\frac { { y_{ T } }^{ 2 } }{ a\cdot a }  }  \\ \sqrt { 1-\frac { { z_{ T } }^{ 2 } }{ a\cdot a }  }  \end{pmatrix}\\ 

 -->




