#include <iostream>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>

typedef std::unordered_map<u_int64_t, std::pair<u_int64_t, u_int64_t>> TransitionMap;

void record_next_state(TransitionMap& transitions, std::vector<u_int64_t>& counts, const int stoneNumber, const int numBlinks, const u_int64_t state, const int blink)
{
    if (blink == numBlinks)
    {
        counts[stoneNumber] += 1;
        // std::cout << counts[stoneNumber] << std::endl;
        return;
    }

    else if (blink == 40)
    {
        std::cout << counts[stoneNumber] << std::endl;
    }


    if (state == 0)
    {
        record_next_state(transitions, counts, stoneNumber, numBlinks, 1, blink+1);
    }
    else 
    {
        const u_int64_t stateLength = static_cast<u_int64_t>(log10(state)) + 1;

        if ((stateLength % 2) == 1)
        {
            record_next_state(transitions, counts, stoneNumber, numBlinks, state * 2024, blink+1);
        }
        else 
        {
            if (transitions.find(state) == transitions.end())
            {
                const u_int64_t breakPoint = static_cast<u_int64_t>(pow(10.0f, (stateLength / 2)));
                // std::cout << "Breakpoint: " << std::to_string(state) << std::endl;
                const u_int64_t nextStateRight = state % breakPoint;
                const u_int64_t nextStateLeft = state / breakPoint;
                transitions[state] = std::make_pair(nextStateLeft, nextStateRight);
            }
            record_next_state(transitions, counts, stoneNumber, numBlinks, transitions[state].first, blink+1);
            record_next_state(transitions, counts, stoneNumber, numBlinks, transitions[state].second, blink+1);
        }
    }
}

int main()
{
    const int numBlinks = 75;

    const int numStones = 8;
    const int stones[numStones] = {2701, 64945, 0, 9959979, 93, 781524, 620, 1};

    // const int numStones = 2;
    // const int stones[numStones] = {125, 17};

    TransitionMap transitions;

    std::vector<u_int64_t> counts(numStones, 0);
    u_int64_t summation = 0;

    for (int stoneNumber = 0; stoneNumber < numStones; ++stoneNumber)
    {
        u_int64_t stone = stones[stoneNumber];
        std::cout << "Stone " << std::to_string(stone) << " processing..." << std::endl;
        record_next_state(transitions, counts, stoneNumber, numBlinks, stone, 0);
        std::cout << "Stone " << std::to_string(stone) << " has " << std::to_string(counts[stoneNumber]) << " children." << std::endl;
        summation += counts[stoneNumber];

        
    }

    std::cout << "Summation: " + std::to_string(summation) << std::endl;

    return 0;
}