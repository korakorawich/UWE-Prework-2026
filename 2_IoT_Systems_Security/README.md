# UWE-IoT-Prework-2026
I9001-Pre-Admission-Preparing-to-Study
# UWE MSc Cyber Security - IoT Systems Security Pre-work

Welcome! This repository contains my C programming submission for the IoT Systems Security module pre-work at UWE Bristol. 

In cybersecurity, especially within IoT systems, the strength of cryptography heavily relies on the unpredictability of random numbers. The goal of this project is to evaluate the statistical properties of a given Pseudo-Random Number Generator (PRNG) to see if it produces a uniform and unbiased distribution.

All four tests in this repository strictly utilize the following required formula to generate integers between 0 and 9:
`int random_number = (int)(10.0*rand()/(RAND_MAX + 1.0));`

Below is a breakdown of my approach for each test:

## 1. Mean Test (`task1_mean.c`)
- **The Concept:** If a PRNG is biased towards higher or lower numbers, the average will skew. A predictable skew is a critical vulnerability in cryptography.
- **My Approach:** I wrote a loop to generate 1,000 random numbers and accumulated their total sum. By dividing the sum by 1,000.0, the program calculates the arithmetic mean. Since the numbers range from 0 to 9, a perfectly uniform distribution should naturally average out to exactly 4.5. 

## 2. Frequency Test (`task2_frequency.c`)
- **The Concept:** A secure system demands uniformity. An attacker shouldn't be able to guess that a specific digit will appear more often than others.
- **My Approach:** To test this efficiently, I generated 10,000 random numbers. Instead of using complex `if-else` statements, I used an array `counts[10]` as frequency buckets. The generated random number acts directly as the array index. The results prove that each digit appears with a roughly equal probability of 10%.

## 3. Odd-Even Test (`task3_oddeven.c`)
- **The Concept:** Parity balance is crucial. If a PRNG favors even over odd numbers, it weakens the binary streams used in encryption algorithms like stream ciphers.
- **My Approach:** I generated 10,000 numbers and applied the modulo operator (`% 2`) to separate them. The program keeps a tally of even and odd outcomes. The final output demonstrates a statistically sound 50/50 split between the two groups.

## 4. Serial Test (`task4_serial.c`)
- **The Concept:** This is about sequential dependence. Even if individual numbers are random, patterns can emerge (e.g., '3' is always followed by '8'). A strong PRNG ensures the previous number does not influence the next.
- **My Approach:** I ran a loop 10,000 times, pulling *two* consecutive random numbers per iteration to form a pair. I used the formula `(first_digit * 10) + second_digit` to map the pair to an index in a 100-element array. The test confirms that all 100 possible combinations (00 to 99) occur with an independent probability of close to 1%.

## How to Compile and Run
You can easily compile any of these tests using GCC. For example:
`gcc task1_mean.c -o mean_test`
`./mean_test`
