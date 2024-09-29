INTRO:
  This project is inspired from the "But what is a Fourier series? ..." from *threeblueonebrown* (link : https://youtu.be/r6sGWTCMz2k?si=WBRE26vYvxb7tbjL)
Which elaborates the capability of fourier transform to follow any closed path with the head of radius vector of rotating circles with various frequencies and radii.

DESCRIPTION: 
  1. repo takes any path that a user draws in a canvas and joins the start and end so that the data is a closed path
  2. applies the equations of bezier curves to smoothen out the rough edges and reduce noice
  3. converts the set of data (coordinates) and parametrises the various radii and phases corresponding to different frequencies just like a fourier transform to
     to a curve into sine/cos. this 2d transformation can be viewed of two transforms by converting the coordinates of path followed into imaginary form, a sine and cos
     representation.
  4. This converted data is then drawn to the canvas from a C++ program utilizing OpenGL library. The output is a path drawn by the sum of various vectors rotating with
     different frequencies and phases

TO RUN:
  1. run in terminal by ` bash run.sh `
  2. draw any path in the canvas
