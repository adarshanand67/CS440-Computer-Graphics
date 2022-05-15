# OpenGL 

## OpenGL links
- https://www.geeksforgeeks.org/mid-point-line-generation-algorithm/


## OpenGL vocabulary


Rendering - The process of converting a 3D model into a 2D image.

Pixels - The smallest unit of a 2D image.

RGB values - The color of a pixel (red, green, blue).

Resolution - The number of pixels in a 2D raster image.

Buffer memory - Temporary storage for data being moved.

Animations - Sequences of frames that are displayed at a constant rate.

Frames - The individual frames(photos) of an animation.

Frame rate - The number of frames displayed per second.

GPU - Graphics Processing Unit - The device that performs the rendering.

Shaders - A program that runs on the GPU.

OpenGL - An API for rendering graphics.

## Graphics pipeline


Graphics pipeline - The sequence of operations that convert a 3D model into a 2D image.

(Application Stage -> Geometry Stage -> Rasterization Stage -> Fragment Stage)

VBO - Vertex Buffer Object - A buffer that stores vertex data.

Mesh - A collection of vertices grouped together in lines or triangles.

Rasterization - task of taking an image described in a vector graphics format (shapes) and converting it into a raster image.

Geometric primitives - The basic shapes that can be drawn on a 2D raster image.

Fragment - The final step in the graphics pipeline.

Fragment Shader - stage that will process a Fragment generated by the Rasterization into a set of colors and a single depth value

Pixel Processing - The process of converting a raster image into a 2D image.

Depth Buffer - A buffer that stores the depth of each pixel.

Lighting - The process of determining the color of a pixel based on the lighting of the scene.

Transparency - The process of blending two colors together.

Vertex Buffer Objects (VBO) - VBOs are used to store the geometry data.

Index Buffer Objects - IBOs are used to store the indices of the geometry.

Vertex Array Objects - VAOs are used to store the state of the geometry.

## OpenGL Basics


GLFW - manage windows and OpenGL contexts, as well as handle joystick, keyboard and mouse input

Context - Think of a context as an object that holds all of OpenGL; when a context is destroyed, OpenGL is destroyed.In order for any 
OpenGL commands to work, a context must be current; all OpenGL commands affect the state of whichever context is current.

glEnableClientState — enable or disable client-side capability (by default, all capabilities are disabled).

glVertexPointer — define an array of vertex data

glClear — clear buffers to preset values

glLoadIdentity — replace the current matrix with the identity matrix

glGenBuffers — generate buffer object names of size n

glBufferData — creates and initializes a buffer object's data store.
