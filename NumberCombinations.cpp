#include <cmath>
#include <array>
#include <conio.h>
#include <string>
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool PrimeNumber(int x) {
		if (x < 2) {
			return false;
		}
		for (int i = 2; i <= x / 2; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
}

bool Tek(int x) {
	return x % 2 != 0;
}

bool Fibonacci(int x, int& index) {
	array<int, 100> fib;
	fib[0] = 1;
	fib[1] = 1;
	if (x == 1) {
		index = 0; // 1. eleman
		return true;
	}
	for (int i = 2; i < 100; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] == x) {
			index = i;
			return true;
		}
		if (fib[i] > x) break;
	}
	return false;
}
bool AmazingNumber(int x) {
	if (x <= 0) return false;
	int toplam = 0;
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			toplam += i;
		}
	}
	return toplam == x;
}
double ortalama(const vector<int>& sayilar) {
	if (sayilar.empty()) return 0;
	double toplam = 0;
	for (int sayi : sayilar) {
		toplam += sayi;
	}
	return toplam / sayilar.size();
}


double geometrikOrtalama(const vector<int>& sayilar) {
	if (sayilar.empty()) return 0;
	double carpim = 1.0;
	for (int sayi : sayilar) {
		carpim *= sayi;
	}
	return pow(carpim, 1.0 / sayilar.size());
}


int main() {
    int adet;
    cout << "-------WELCOME-------" << endl;
    cout << "HOW MANY NUMBERS WILL YOU ENTER: ";
    cin >> adet;

    vector<int> allNumbers;
    vector<int> primeNumbers;
    vector<int> nonPrimeNumbers;
    vector<int> fibonacciNumbers;
    vector<int> nonFibonacciNumbers;

    for (int i = 0; i < adet; i++) {
        int number;
        cout << "\nENTER NUMBER [" << i + 1 << "]: ";
        cin >> number;

        allNumbers.push_back(number);

        bool isPrime = PrimeNumber(number);
        bool isOdd = Tek(number);
        int fibIndex = -1;
        bool isFib = Fibonacci(number, fibIndex);
        bool isPerfect = AmazingNumber(number);

        cout << "\n-------RESULTS-------" << endl;

        if (isPrime) {
            cout << "-> NUMBER IS PRIME" << endl;
            primeNumbers.push_back(number);
        }
        else {
            cout << "-> NUMBER IS NOT PRIME" << endl;
            nonPrimeNumbers.push_back(number);
        }

        if (isOdd)
            cout << "-> NUMBER IS ODD" << endl;
        else
            cout << "-> NUMBER IS EVEN" << endl;

        if (isFib) {
            cout << "-> NUMBER IS IN FIBONACCI SEQUENCE AS ELEMENT " << fibIndex + 1 << endl;
            fibonacciNumbers.push_back(number);
        }
        else {
            cout << "-> NUMBER IS NOT IN FIBONACCI SEQUENCE" << endl;
            nonFibonacciNumbers.push_back(number);
        }

        if (isPerfect)
            cout << "-> NUMBER IS PERFECT" << endl;
        else
            cout << "-> NUMBER IS NOT PERFECT" << endl;
    }

    // SIRALAMA
    sort(allNumbers.begin(), allNumbers.end());
    cout << "\n-------SORTED NUMBERS-------" << endl;
    for (int num : allNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // ORTAK ÖZELLİKLER
    cout << "\n-------SHARED FEATURES-------" << endl;
    for (int num : allNumbers) {
        bool isPrime = PrimeNumber(num);
        int fibIndex = -1;
        bool isFib = Fibonacci(num, fibIndex);
        bool isPerfect = AmazingNumber(num);

        if (isPrime && isFib)
            cout << "-> " << num << " IS BOTH PRIME AND FIBONACCI" << endl;
        if (isPrime && isPerfect)
            cout << "-> " << num << " IS BOTH PRIME AND PERFECT" << endl;
        if (isFib && isPerfect)
            cout << "-> " << num << " IS BOTH FIBONACCI AND PERFECT" << endl;
    }

    // EN KÜÇÜK VE EN BÜYÜK
    if (!allNumbers.empty()) {
        cout << "\n-------EXTREMES-------" << endl;
        cout << "-> SMALLEST NUMBER: " << allNumbers.front() << endl;
        cout << "-> LARGEST NUMBER: " << allNumbers.back() << endl;
    }
    // GIRILEN SAYILARIN LISTESI
    cout << "\n-------GIRILEN SAYILARIN LISTESI-------" << endl;
    if (!allNumbers.empty()) {
        cout << "-> GIRILEN " << allNumbers.size() << " ADET SAYI:" << endl;
        for (int i = 0; i < allNumbers.size(); i++) {
            cout << "   [" << i + 1 << "] " << allNumbers[i] << endl;
        }
    }
    else {
        cout << "-> HIC SAYI GIRILMEDI" << endl;
    }
    cout << "---------------------------------------" << endl;
    // ORTALAMA HESAPLAMALARI
    cout << "\n-------ORTALAMA ANALIZLERI-------" << endl;

    auto ortalama = [](const vector<int>& sayilar) -> double {
        if (sayilar.empty()) return 0;
        double toplam = 0;
        for (int s : sayilar) toplam += s;
        return toplam / sayilar.size();
        };

    auto geometrikOrtalama = [](const vector<int>& sayilar) -> double {
        if (sayilar.empty()) return 0;
        double carpim = 1.0;
        for (int s : sayilar) carpim *= s;
        return pow(carpim, 1.0 / sayilar.size());
        };

    // ASAL SAYILAR
    cout << "\n-> ASAL SAYILAR:";
    if (!primeNumbers.empty()) {
        cout << "\n   ARITMETIK ORTALAMA: " << ortalama(primeNumbers);
        cout << "\n   GEOMETRIK ORTALAMA: " << geometrikOrtalama(primeNumbers);
    }
    else {
        cout << "\n   VERI YOK";
    }

    // NORMAL SAYILAR
    cout << "\n\n-> ASAL OLMAYAN SAYILAR:";
    if (!nonPrimeNumbers.empty()) {
        cout << "\n   ARITMETIK ORTALAMA: " << ortalama(nonPrimeNumbers);
        cout << "\n   GEOMETRIK ORTALAMA: " << geometrikOrtalama(nonPrimeNumbers);
    }
    else {
        cout << "\n   VERI YOK";
    }

    // FIBONACCI SAYILAR
    cout << "\n\n-> FIBONACCI SAYILAR:";
    if (!fibonacciNumbers.empty()) {
        cout << "\n   ARITMETIK ORTALAMA: " << ortalama(fibonacciNumbers);
        cout << "\n   GEOMETRIK ORTALAMA: " << geometrikOrtalama(fibonacciNumbers);
    }
    else {
        cout << "\n   VERI YOK";
    }

    // FIBONACCI OLMAYAN SAYILAR
    cout << "\n\n-> FIBONACCI DISI SAYILAR:";
    if (!nonFibonacciNumbers.empty()) {
        cout << "\n   ARITMETIK ORTALAMA: " << ortalama(nonFibonacciNumbers);
        cout << "\n   GEOMETRIK ORTALAMA: " << geometrikOrtalama(nonFibonacciNumbers);
    }
    else {
        cout << "\n   VERI YOK";
    }

    // TUM SAYILAR
    cout << "\n\n-> TUM GIRILEN SAYILAR:";
    if (!allNumbers.empty()) {
        cout << "\n   ARITMETIK ORTALAMA: " << ortalama(allNumbers);
        cout << "\n   GEOMETRIK ORTALAMA: " << geometrikOrtalama(allNumbers);
    }
    else {
        cout << "\n   VERI YOK";
    }

    return 0;
}


