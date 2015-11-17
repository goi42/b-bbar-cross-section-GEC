plotbranches.C is a less flexible version of makeplots.C (in ~/algorithms/)

I recommend compiling it.

There are 2 options:
The 1st: "b" to specify a branch, "f" to specify the files, "c" to specify a cut, "C" to save canvas.C files; these may be used in combination. Blank or "d" uses default parameters (see code).
The 2nd: "norm" is the default option and plots normalized histograms. It's just the draw option for MyTree->Draw(branch,cuts,option).

It should be able to take any number of years, decays, filetypes (MC, data, or both), and branches and plot them with a specified set of cuts (that can vary by file, branch, and/or decay) in any permutation with any of them on top of each other, and print them out on a series of canvases all printed into a .pdf or .ps or whatever, with a summary page at the end.

Right now, it will break if you don't provide the right kind of input (int, string, etc.).

The counters that get printed out correspond to looped variables, meaning if there are 8 canvases, the canvas number will go from 0 to 7.
