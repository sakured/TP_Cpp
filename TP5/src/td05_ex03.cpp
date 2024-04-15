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
    Ace = 0,
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
};

struct Card {
    CardKind kind;
    CardValue value;

    size_t hash() const;
};

bool operator==(Card const& c1, Card const& c2) {
    return c1.kind == c2.kind && c1.value == c2.value;
}

size_t Card::hash() const {
    size_t hash { static_cast<size_t>(value) };
    if (kind == CardKind::Diamond) {
        hash += 13;
    } else if (kind == CardKind::Club) {
        hash += 2 * 13;
    } else if (kind == CardKind::Spade) {
        hash += 3 * 13;
    }
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
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value { (static_cast<unsigned int>(card.value)+1) % 14 };

    if (card_value < 10) {
        name += '0' + card_value;
    } else if (card_value == 10) {
        name += "10";
    } else if (card_value == 11) {
        name += 'V';
    } else if (card_value == 12) {
        name += 'Q';
    } else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    } else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    } else if (card.kind == CardKind::Club) {
        name += "Club";
    } else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

std::unordered_map<Card, int> card_counter_map(std::vector<Card> vec_cards) {
    std::unordered_map<Card, int> card_counter_map {};
    for (Card card : vec_cards) {
        auto key = (card_counter_map.find(card));
        if (key == card_counter_map.end()) {
            card_counter_map.insert(std::make_pair(card, 1));
        } else {
            (*key).second ++;
        }
    }
    return card_counter_map;
}

int main()
{
    std::vector<Card> vec_cards { get_cards(200) };
    std::unordered_map<Card, int> map_cards { card_counter_map(vec_cards) };
    for (std::pair<Card, int> pair : map_cards) {
        std::cout << card_name(pair.first) << " (hash = " << pair.first.hash() << ") : " << pair.second << " occurences" << std::endl;
    }

    return 0;
}