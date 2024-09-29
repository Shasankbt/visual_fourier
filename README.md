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
  1. run the default in terminal by `bash run.sh ` *(number of vectors : 101, speed : 0.1s)*
  2. adjust the number of vectors and the speed scale (can be adjusted for viewing) by using flags `-n` and `-s` respectively
      eg : to use 21 vectors and to run at 1 second per loop, run `bash run.sh -n 10 -s 1` *(note that number of vectors = 2*n+1)*
  3. draw any path in the canvas

DEBUG:
  1. if the executable is not in the repo, run `make`. This will store the executables from C++ to the `object_files/` directory
  2. if issues in compiling C++ code due to simplecpp, go to `simplecpp/` and then run `bash configure.sh` 
