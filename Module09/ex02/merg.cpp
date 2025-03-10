#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) {
    parse_input(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        original_sequence = other.original_sequence;
        vector_sequence = other.vector_sequence;
        deque_sequence = other.deque_sequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_and_display() {
    std::cout << "Before: ";
    print_sequence(original_sequence);
    
    clock_t start = clock();
    ford_johnson_sort(vector_sequence);
    clock_t end = clock();
    double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    start = clock();
    ford_johnson_sort(deque_sequence);
    end = clock();
    double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    print_sequence(vector_sequence);
    
    std::cout << "Time to process a range of " << vector_sequence.size() << " elements with std::vector: "
              << vector_time << " s" << std::endl;
    std::cout << "Time to process a range of " << deque_sequence.size() << " elements with std::deque: "
              << deque_time << " s" << std::endl;
}

void PmergeMe::parse_input(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0)
            throw std::runtime_error("Error");
        original_sequence.push_back(num);
    }
    vector_sequence = original_sequence;
    deque_sequence.assign(original_sequence.begin(), original_sequence.end());
}

void PmergeMe::binary_insert(std::vector<int> &arr, int value) {
    std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}

void PmergeMe::binary_insert(std::deque<int> &arr, int value) {
    std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}

void PmergeMe::recursive_sort(std::vector<s_pair> &pairs, int left, int right) {
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    recursive_sort(pairs, left, mid);
    recursive_sort(pairs, mid + 1, right);
    
    std::vector<s_pair> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (pairs[i].high <= pairs[j].high)
            temp.push_back(pairs[i++]);
        else
            temp.push_back(pairs[j++]);
    }
    
    while (i <= mid)
        temp.push_back(pairs[i++]);
    while (j <= right)
        temp.push_back(pairs[j++]);
    
    std::copy(temp.begin(), temp.end(), pairs.begin() + left);
}

template<typename Container>
void PmergeMe::ford_johnson_sort(Container &arr) {
    int n = arr.size();
    if (n <= 1)
        return;
    
    std::vector<s_pair> pairs;
    typename Container::iterator it = arr.begin();
    while (it + 1 != arr.end()) {
        if (*it < *(it + 1))
            pairs.push_back({*(it + 1), *it});
        else
            pairs.push_back({*it, *(it + 1)});
        it += 2;
    }
    
    recursive_sort(pairs, 0, pairs.size() - 1);
    
    Container sorted;
    sorted.push_back(pairs[0].high);
    for (const auto &p : pairs) {
        sorted.push_back(p.high);
        binary_insert(sorted, p.low);
    }
    
    if (n % 2 != 0)
        binary_insert(sorted, arr.back());
    
    arr = sorted;
}

void PmergeMe::print_sequence(const std::vector<int> &seq) {
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << seq[i] << (i + 1 < seq.size() ? " " : "\n");
}

int main(int argc, char **argv) {
    try {
        PmergeMe sorter(argc, argv);
        sorter.sort_and_display();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

