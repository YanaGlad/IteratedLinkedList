#include <iostream>
#include <list>
#include <vector>

// добавление
template<class T>
void push(std::list<T> &lst, T elem) {
    if (lst.empty()) {
        lst.push_back(elem);
        return;
    }

    auto it = lst.begin();
    while (it != lst.end() && elem < *it) {
        it++;
    }

    if (it == lst.end()) lst.push_back(elem);
    else lst.insert(it, elem);
}

//поиск минимального элемента. Необходимо чтобы оператор у класса Т был переопределен
template<class T>
T findMin(std::list<T> &list) {

    auto iter = list.begin();
    T min = *iter;
    for (auto &it: list) {
        if (it < min) min = it;
    }
    return min;
}

template<class T>
void toString(std::list<T> &list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T remove(std::list<T> &lst) {
    if (lst.empty()) throw std::exception(); //не можем удалять из пустого списка

    T res = lst.front();
    lst.pop_front();

    return res;
}

// класс музыкальный альбом
class MusicAlbum {

public:
    std::string name;
    std::string fakeName;
    std::string albumName;
    int songsCount;
    int productYear;
    int soldCount;

    MusicAlbum(std::string name,
               std::string fakeName,
               std::string albumName,
               int songsCount,
               int productYear,
               int soldCount) {
        this->name = name;
        this->fakeName = fakeName;
        this->songsCount = songsCount;
        this->productYear = productYear;
        this->soldCount = soldCount;
    }

    ~MusicAlbum() = default;
};

//получить вектор альбомов, которые обладают значением (число проданных альбомов) большим, чем задано
std::vector<MusicAlbum> findMoreThan(std::list<MusicAlbum> &list, int moreThan) {
    std::vector<MusicAlbum> vector;
    auto iter = list.begin();
    MusicAlbum min = *iter;
    for (auto &it: list) {
        if (it.soldCount > moreThan)
            vector.push_back(it);
    }
    return vector;
}


bool operator==(const MusicAlbum &a, const MusicAlbum &b) {
    return a.name == b.name && a.albumName == b.albumName && a.songsCount == b.songsCount &&
           a.productYear == b.productYear;
}

bool operator!=(const MusicAlbum &a, const MusicAlbum &b) {
    return a.name != b.name || a.albumName != b.albumName || a.songsCount != b.songsCount ||
           a.productYear != b.productYear;
}

bool operator>(const MusicAlbum &a, const MusicAlbum &b) {
    return a.soldCount > b.soldCount;
}

bool operator<(const MusicAlbum &a, const MusicAlbum &b) {
    return a.soldCount < b.soldCount; // сравниваем по количеству проданных экзмепляров
}

std::ostream &operator<<(std::ostream &os, const MusicAlbum &musicAlbum) {
    return os << "Name: " << musicAlbum.name << ", fake name: " << musicAlbum.fakeName
              << ", album name " << musicAlbum.albumName << ", year: " << musicAlbum.productYear << ", songs count: "
              << musicAlbum.songsCount << ", amount sold: " << musicAlbum.soldCount << std::endl;
}

int main() {
    std::list<MusicAlbum> list;
    push(list, MusicAlbum("name1", "fakeName1", "album1", 20, 2002, 20));
    push(list, MusicAlbum("name2", "fakeName2", "album2", 10, 2022, 30));
    push(list, MusicAlbum("name3", "fakeName3", "album3", 3, 2012, 10));
    push(list, MusicAlbum("name4", "fakeName4", "album4", 44, 2020, 25));
    push(list, MusicAlbum("name5", "fakeName5", "album5", 5, 2011, 60));

    for (auto &iter: list) std::cout << iter << "\t";

    std::cout << "Min is: " << findMin(list) << std::endl;

    return 0;
}
