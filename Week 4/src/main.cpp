#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include "Queue.hpp"

//Quick sort template function
//source: http://www.algolist.net/Algorithms/Sorting/Quicksort
template <typename T, size_t size>
void sort(T (&arr)[size], int left = 0, int right = size - 1) {
    int i = left, j = right;
    T tmp, pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        sort(arr, left, j);
    if (i < right)
        sort(arr, i, right);
}

//Print the array values on the screen
template <typename T, size_t size>
void print_array(T (&arr)[size], const std::string& title) {
    std::cout << title << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    float floats[] = {8.2f, 7.6f, 7.2f, 8.0f, 6.5f, 10.0f, 4.6f};
    print_array(floats, "Float array before sort:");
    sort(floats);
    print_array(floats, "Float array after sort:");
    std::cout << std::endl;

    std::string strings[] = {"Aap", "Noot", "mies", "Wim", "Zus", "Jet"};
    print_array(strings, "String array before sort:");
    sort(strings);
    print_array(strings, "String array after sort:");
    std::cout << std::endl;

    Queue<std::string>* queue = new Queue<std::string>();
    queue->push("Aap");
    queue->push("Noot");
    queue->push("Mies");
    queue->push("Wim");
    std::string str = queue->pop();  //Return the first element in the list

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    std::vector<std::string> before(colours.size()), after(colours.size()), upper(colours.size()), unique(colours.size());

    // 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    unsigned n = std::count_if(colours.begin(), colours.end(), [](std::string s) { return s <= "purple"; });
    before.resize(n);
    after.resize(colours.size() - n);
    std::partition_copy(colours.begin(), colours.end(), before.begin(), after.begin(), [](std::string s) { return s <= "purple"; });

    std::cout << "1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na" << std::endl;
    std::for_each(before.begin(), before.end(), [](auto val) { std::cout << "< " << val << std::endl; });
    std::for_each(after.begin(), after.end(), [](auto val) { std::cout << "> " << val << std::endl; });
    std::cout << std::endl;

    // 2) alle elementen UPPERCASE te maken.
    std::transform(colours.begin(), colours.end(), upper.begin(), [](std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    });
    std::cout << "2) alle elementen UPPERCASE te maken." << std::endl;
    std::for_each(upper.begin(), upper.end(), [](auto val) { std::cout << "- " << val << std::endl; });
    std::cout << std::endl;

    // 3) alle dubbele te verwijderen
    std::cout << "3) alle dubbele te verwijderen" << std::endl;
    std::partial_sort_copy(colours.begin(), colours.end(), unique.begin(), unique.end());
    unique.erase(std::unique(unique.begin(), unique.end()), unique.end());
    std::for_each(unique.begin(), unique.end(), [](auto val) { std::cout << "- " << val << std::endl; });
    std::cout << std::endl;

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    std::vector<double>
        numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    std::vector<double> positive(numbers.size());

    // 1) alle negatieve elementen te verwijderen
    std::cout << "1) alle negatieve elementen te verwijderen" << std::endl;
    n = std::count_if(numbers.begin(), numbers.end(), [](double d) { return d >= 0.0; });
    positive.resize(n);
    std::copy_if(numbers.begin(), numbers.end(), positive.begin(), [](double d) { return d >= 0.0; });
    std::for_each(positive.begin(), positive.end(), [](auto d) { std::cout << d << std::endl; });
    std::cout << std::endl;

    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    std::cout << "2) voor alle elementen te bepalen of ze even of oneven zijn" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [](double d) { std::cout << d << " = " << (std::fmod(d, 2) == 0 ? "even\n" : "odd\n"); });
    std::cout << std::endl;

    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    std::cout << "3) de som, het gemiddelde, en het product van alle getallen te berekenen" << std::endl;
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    double average = sum / numbers.size();
    auto product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Product: " << product << std::endl;
}