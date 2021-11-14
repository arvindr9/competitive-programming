# Contest reflections

## Saturday Nov 14

2021 zhejiang provincial

K: not too bad, shouldn't have given up on my idea of making things circular

B: kept making bugs, but good practice

2021 CCPC Guilin Onsite

E (Buy and Delete): min-cost cycle. Took me a while to find the observation that the answer is at most two and it reduces to finding the min-cost cycle. Bricked in finding min-cost cycle (Had a wrong sol initially, and solution is to run dijsktra n times on the original graph and the reverse graph, and iterate through intermediate edges to get the min cost)

G, I: kind of simple

D: We kept bricking and finding countercases to our ideas (i.e. moving the smallest / largest element). I realized that the first element was nondecreasing during the process, which motivated adding each element one by one from left to right. Naively adding things one by 1 from left to right didn't work, and I needed a way to make sure I have larger elements in the left side and smaller elements in the right side, which motivated finding a decreasing subsequence and performing swaps with index i. Got AC after 4 hours which was pretty late

C: Some connected graph that contains the root needs to contain A, and everything else needs to contain C. Unsure how to do this problem efficiently when the tree is a line

J: Maybe use a suffix automoton to compute the kth string at depth d (unsure how to do this efficiently). But we also need to recover the indices, so maybe something with suffix array?

L: The strucutre of the wires have to be very dense (i.e. the extreme wire has to exist, and each additional wire is defined by adding 1 to an endpoint of the previous wire).