#ifndef SORTING_HAT_MODEL_H
#define SORTING_HAT_MODEL_H

namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
            public:
                int predict(const float* x) {
                    // 简单版本，假设答案随机，正式版可以替换这里
                    float sum = 0;
                    for (int i = 0; i < 10; i++) {
                        sum += x[i];
                    }
                    int house = (int(sum) % 4); // 0, 1, 2, 3
                    return house;
                }
            };
        }
    }
}

#endif
