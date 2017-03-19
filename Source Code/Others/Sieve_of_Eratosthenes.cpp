#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

// Sieve of Eratosthenes

void findPrime1(int num)
{
    vector<int> Primes(num + 1);

    for (int i = 0; i <= num; i++) {
        if (i == 0 || i == 1) Primes[i] = 0;
        else Primes[i] = 1;
    }


    for (int i = 2; i <= sqrt(num); i++) {
        if (Primes[i] == 1) {
            for (int k = 2; i * k <= num; k++) {
                Primes[i * k] = 0;
            }
        }
    }


//    for (int i = 0; i <= num; ++i) {
//        if (Primes[i] == 1) cout << i << " ";
//    }

}

void findPrime2(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<bool> prime(n+1);
    fill(prime.begin(), prime.end(), true);

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
//    for (int p=2; p<=n; p++)
//       if (prime[p])
//          cout << p << " ";
}

void findPrime3(int n)
{
    vector<int> Prime(n + 1);
    for (int i = 0; i <= n; i++) Prime[i] = i;

    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = i * 2; j <= n; j += i) {
            Prime[j] = 0;
        }
    }

//    for (int i = 2; i <= n; ++i) if (Prime[i] != 0) cout << Prime[i] << " ";

}

int main()
{
    int num;
    clock_t time;

    cin >> num;

    time = clock();
    findPrime1(num);
    time = clock() - time;
    cout << float(time) / CLOCKS_PER_SEC << "s" << endl;

    time = clock();
    findPrime2(num);
    time = clock() - time;
    cout << float(time) / CLOCKS_PER_SEC << "s" << endl;

    time = clock();
    findPrime3(num);
    time = clock() - time;
    cout << float(time) / CLOCKS_PER_SEC << "s" << endl;

}
