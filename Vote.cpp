/*
    Digital Voting System (OOP in C++)
    ------------------------------------
    Demonstrates encapsulation, abstraction, and separation of concerns
    using classes: Candidate, Voter, and VotingSystem.

    Compile:  g++ -std=c++17 voting_system.cpp -o voting_system
    Run:      ./voting_system
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

// ---------------------------------------------------------
// Candidate class
// ---------------------------------------------------------
class Candidate {
private:
    int id;
    std::string name;
    std::string party;
    int voteCount;

public:
    Candidate(int id, const std::string& name, const std::string& party)
        : id(id), name(name), party(party), voteCount(0) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getParty() const { return party; }
    int getVoteCount() const { return voteCount; }

    void addVote() { voteCount++; }

    void display() const {
        std::cout << id << ". " << name << " (" << party << ")\n";
    }
};

// ---------------------------------------------------------
// Voter class
// ---------------------------------------------------------
class Voter {
private:
    std::string voterId;   // e.g. national ID / registration number
    std::string name;
    bool hasVoted;

public:
    Voter(const std::string& voterId, const std::string& name)
        : voterId(voterId), name(name), hasVoted(false) {}

    std::string getVoterId() const { return voterId; }
    std::string getName() const { return name; }
    bool getHasVoted() const { return hasVoted; }

    void markVoted() { hasVoted = true; }
};

// ---------------------------------------------------------
// VotingSystem class - manages candidates, voters, and voting logic
// ---------------------------------------------------------
class VotingSystem {
private:
    std::vector<Candidate> candidates;
    std::map<std::string, Voter> registeredVoters; // keyed by voterId

public:
    // ---- Setup ----
    void addCandidate(int id, const std::string& name, const std::string& party) {
        candidates.emplace_back(id, name, party);
        std::cout << "Candidate added: " << name << " (" << party << ")\n";
    }

    void registerVoter(const std::string& voterId, const std::string& name) {
        if (registeredVoters.find(voterId) != registeredVoters.end()) {
            std::cout << "Voter ID " << voterId << " is already registered.\n";
            return;
        }
        registeredVoters.emplace(voterId, Voter(voterId, name));
        std::cout << "Voter registered: " << name << " (ID: " << voterId << ")\n";
    }

    // ---- Core voting logic ----
    void showCandidates() const {
        std::cout << "\n--- Candidates ---\n";
        for (const auto& c : candidates) c.display();
        std::cout << "------------------\n";
    }

    bool castVote(const std::string& voterId, int candidateId) {
        auto voterIt = registeredVoters.find(voterId);
        if (voterIt == registeredVoters.end()) {
            std::cout << "Error: Voter ID not registered.\n";
            return false;
        }

        Voter& voter = voterIt->second;
        if (voter.getHasVoted()) {
            std::cout << "Error: " << voter.getName() << " has already voted.\n";
            return false;
        }

        auto candIt = std::find_if(candidates.begin(), candidates.end(),
            [candidateId](const Candidate& c) { return c.getId() == candidateId; });

        if (candIt == candidates.end()) {
            std::cout << "Error: Invalid candidate ID.\n";
            return false;
        }

        candIt->addVote();
        voter.markVoted();
        std::cout << "Vote cast successfully for " << candIt->getName() << "!\n";
        return true;
    }

    // ---- Results ----
    void showResults() const {
        std::cout << "\n=== Voting Results ===\n";
        std::vector<Candidate> sorted = candidates;
        std::sort(sorted.begin(), sorted.end(),
            [](const Candidate& a, const Candidate& b) {
                return a.getVoteCount() > b.getVoteCount();
            });

        int totalVotes = 0;
        for (const auto& c : candidates) totalVotes += c.getVoteCount();

        for (const auto& c : sorted) {
            double pct = totalVotes == 0 ? 0.0 : (100.0 * c.getVoteCount() / totalVotes);
            std::cout << c.getName() << " (" << c.getParty() << "): "
                      << c.getVoteCount() << " votes (" << pct << "%)\n";
        }

        std::cout << "-----------------------\n";
        std::cout << "Total votes cast: " << totalVotes << "\n";

        if (!sorted.empty() && totalVotes > 0) {
            std::cout << "Winner: " << sorted.front().getName() << "\n";
        }
        std::cout << "=======================\n";
    }
};

// ---------------------------------------------------------
// Simple console menu to demonstrate the system
// ---------------------------------------------------------
void showMenu() {
    std::cout << "\n===== Digital Voting System =====\n";
    std::cout << "1. Show Candidates\n";
    std::cout << "2. Register Voter\n";
    std::cout << "3. Cast Vote\n";
    std::cout << "4. Show Results\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    VotingSystem system;

    // Pre-load sample candidates
    system.addCandidate(1, "Alice Johnson", "Green Party");
    system.addCandidate(2, "Bob Smith", "Blue Party");
    system.addCandidate(3, "Carol Lee", "Red Party");

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            system.showCandidates();
        } else if (choice == 2) {
            std::string id, name;
            std::cout << "Enter Voter ID: ";
            std::cin >> id;
            std::cout << "Enter Voter Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            system.registerVoter(id, name);
        } else if (choice == 3) {
            std::string id;
            int candId;
            system.showCandidates();
            std::cout << "Enter your Voter ID: ";
            std::cin >> id;
            std::cout << "Enter Candidate ID to vote for: ";
            std::cin >> candId;
            system.castVote(id, candId);
        } else if (choice == 4) {
            system.showResults();
        } else if (choice == 5) {
            std::cout << "Exiting. Thank you for using the Digital Voting System.\n";
            break;
        } else {
            std::cout << "Invalid option. Please choose 1-5.\n";
        }
    }

    return 0;
}