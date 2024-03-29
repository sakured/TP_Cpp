#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    size_t hash();
};

bool operator==(Card const& c1, Card const& c2) {
    return c1.kind == c2.kind && c1.value == c2.value;
}

size_t Card::hash() {
    size_t hash {};
    
    return hash;
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.emplace_back(static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13));
    }
    return cards;
}

int main()
{
    std::vector<Card> vec_cards { get_cards(100) };

    return 0;
}