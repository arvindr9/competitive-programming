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

## Tuesday Nov 17

L: trivial

E: Bricked E in the beginning even though it's easy

F: Wasn't able to prove convexity in the beginning. Accidentally binary searched on
finite differences, leading to precision issues. Changed it to ternary search
(I guess this was an opportunity for me to learn ternary search) and got AC easily

M: Didn't read the constraints in the beginning and thus wasn't able to figure it out
for some time. It reduced to an n^2 tree dp, which was nontrivial to implement, but
I think my timing was good.

H: Misread the problem in the beginning, became trivial after I was given the correct
interpretation.

J: made observations during the contest (i.e. query frequency of a bit in the
segtree). Misread the update, didn't realize it was a range max update with paramater
x. Either way, the solution requires segtree beats, which I wouldn't have been able to do within the limited timespan of the contest.

## Tuesday Nov 24

(CF Global round)

A, B: solved quickly
C: was skeptical that binsearch would be too hard for a C, spent a too much time debugging binsearch
D: had a wrong assumption for the entire contest, realized it was easy when I was upsolving it
E: had some observations but unsure (maybe i was also a bit demoralized that i hadn't gotten D)

## Sun Nov 28 

### (https://codeforces.com/contest/1609, Deltix)

B: wrote too much code, could've been much faster
C: Mixup between n and ne, waited too long to write a brute force (15 min time diff between WA and AC)
D: Misread the constraints
E: should've been free, same as https://codeforces.com/problemset/problem/750/

Issues: speed (for ~2300 perf) and missing a free problem (for 2500+ perf)

## Tue Nov 29

### Educational 117 (https://codeforces.com/contest/1612)

B: Should've been a 5-min prob
C: ok
D: had slightly wrong ideas (WA at 0:31) and eventually got it at 0:43
E: a bit on the slow side to impl (30 min), 20 more min to fix. Need more practice
G: kinda too late to think about it, but I think I can do it now

### SERC 21 (https://codeforces.com/gym/103438)

N: Hard for me but many ppl solved it within 8 min
J: Had some observations, Jeffrey helped me figure it out, ez 13 min AC
F: Figured it out not that late, but underestimated time to code C
C: weird to think about negative indexing, made too large of a constant factor (maybe I should change my style for convolution code?)
E: I think I have a 1D version but details might be finnicky?

## Mon Dec 6

### Upsolving SERC 21

E: Tried implementing the 1D version. Struggled with indexing, and later realized I had a wrong assumption, as I can only use the segtree for j s.t. 1 <= j <= i - 2
when computing dp[i]. Spent too long on this problem (AC after 2 hr 30 min)
G, K, M: bricked thinking about it, Jeffrey told me later how to do G and a high level hint for K (look at the smallest and second smallest leaf)

## Tue Dec 7

### Upsolving SERC 21

K: Coded something slightly wrong (I tried taking a path from the smallest to second smallest, then third smallest to 4th smallest and so on),
later fixed it after thinking about it for a while.


