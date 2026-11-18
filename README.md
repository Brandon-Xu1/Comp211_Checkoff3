# Run-Length Encoding in C

For my COMP 211 checkoff, I explored run-length encoding (RLE), a lossless compression method that stores consecutive copies of a value as a single count and value. “Lossless” means we can recover the original data exactly.

## What I explored

I started by tracing `AAAAABBCCDAAA` by hand. It becomes `(5,A) (2,B) (2,C) (1,D) (3,A)`. The first five A’s and the last three A’s form separate runs because other letters appear between them.

I then looked at how to implement that logic in C. The detail that helped me understand the loop was figuring out when to save a run. When the first B appears, the program knows it has finished counting the first five A’s. At the end of the string, there’s no next character to trigger that step, so the program saves the last three A’s after the loop.

## What surprised me

I assumed compression would always make the data smaller. These two inputs changed how I thought about that:

| Input | Original size | Size with 2-byte RLE pairs |
| --- | ---: | ---: |
| `AAAABBBB` | 8 bytes | 4 bytes |
| `ABABABAB` | 8 bytes | 16 bytes |

Both strings have four A’s and four B’s. The first needs only two pairs. In the second, every letter gets its own count of one, so the encoded data actually doubles in size. I can see the repeating `AB` pattern immediately, but RLE only checks whether neighboring values match.

The same idea helped me understand image compression. In a pixel-art game, a row of solid blue sky can be stored as one long run. In a forest photo, neighboring leaves might look like the same green to us even though their pixels have slightly different values. Each change starts another run.

## Run the demo

```sh
cc -std=c11 -Wall -Wextra rle_example.c -o rle_example
./rle_example
./rle_example AAAABBBB
./rle_example ABABABAB
```

The program prints the pairs, compares the original and encoded sizes, and decodes the result to check that it matches the input.

## Slides and references

- [Presentation slides](https://docs.google.com/presentation/d/1nXSUh3U_Nl23JYP7xbprlVg_zC-77ZnT7KhzIf4ag_o/edit?slide=id.rle_streamline_slide_7#slide=id.rle_streamline_slide_7)
- [ChatGPT conversation about RLE](https://chatgpt.com/share/6afe28f8-6b00-83e9-8f85-cd658e077c27)