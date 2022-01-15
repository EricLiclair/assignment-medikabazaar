# random testing for values

import random


def get_random_speed():
    return str(random.randint(200, 500))


# generate number of test cases
t = random.randint(100, 1000)
print(t)

for i in range(t):
    # generate the size of speeds of cars
    n = random.randint(2, 10)
    print(n)

    # generating a list of speed of cars of the generated list size
    print(" ".join([get_random_speed() for _ in range(n)]))
