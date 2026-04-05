Header-only file for quick and easy Vector2s. C-style string template for printing results to the console.

Drop the header into whatever project needs a quick solution for Vector2D math, include and compile.

Vector2 objects contain and X and Y value, and have operator overloads for doing math between Vector2s, or scaling them with numbers.

================================================

non-operator functions include:

Magnitude() -> (x * x + y * y )
Length() -> sqrt(Magnitude)

Vector2::Normalized(vec) -> the size of the vector, divided by len if len > 0
Vector2.Normalize() -> mutates Vector2 object, normalizes size of vector.

Vector2::Distance(v1, v2) -> distance between two vectors
Vector2.Distance(vec) -> distance between parent vector and passed vector

Vector2::Zero() -> presents a Vector2 with a value of (0,0)
Vector2.New() -> mutates Vector2 object, changes value to (0, 0)

Also an optional format and functions for printing out the Vector2 as a C string, to minimize includes.

Optionally remove the template at the bottom to only include cmath, and use Vector2D.c_str() to print to the console when needed elsewhere.
