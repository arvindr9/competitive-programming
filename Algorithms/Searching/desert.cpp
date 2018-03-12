/**
 * Desert Crossing (1992 IOI, Adapted)
 * A group of desert nomads is working together to
 * try to get one of their group across the desert.
 * Each nomad can carry a certain number of quarts
 * of water, and each nomad drinks a certain amount
 * of water per day, but the nomads can carry differing
 * amounts of water, and require different amounts of
 * water. Given the carrying capacity and drinking requirements
 * of each nomad, find the minimum number of nomads required to
 * get at least one nomad across the desert.
 * 
 * All the nomads must survive, so every nomad that starts
 * out must either turn back at some point, carrying enough
 * water to get back to the start or must reach the other
 * side of the desert. However, if a nomad has surplus water
 * when it is time to turn back, the water can be given to
 * their friends, if their friends can carry it.
 * 
 * Each nomad p_i can carry c_i and needs V_i
 * 
 *
 **/

#include <bits/stdc++.h>

using namespace std;