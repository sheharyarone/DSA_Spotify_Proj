#include <iostream>
#include <string>
#include <list>

// Define a struct to represent the nodes (artists) in the multi-graph
struct Artist
{
    std::string name;
    // Other attributes of the artist, such as average length of their songs or genre
    int average_length;
    std::string genre;
    // List of edges (collaborations) that are connected to the node
    std::list<std::pair<std::string, int>> collaborations;
};

// Define a struct to represent the multi-graph
struct MultiGraph
{
    // Number of nodes (artists) and edges (collaborations) in the graph
    int num_nodes;
    int num_edges;
    // List of nodes (artists) in the graph
    std::list<Artist> nodes;
};

// Implement a function to add a new artist to the multi-graph
void addArtist(MultiGraph &graph, const std::string &name, int average_length, const std::string &genre)
{
    // Create a new artist object
    Artist artist{name, average_length, genre};
    // Add the artist to the list of nodes in the multi-graph
    graph.nodes.push_back(artist);
    graph.num_nodes++;
}

// Implement a function to add a new collaboration between two artists to the multi-graph
void addCollaboration(MultiGraph &graph, const std::string &artist1, const std::string &artist2, int weight)
{
    // Find the artist objects for the two artists
    Artist *a1 = nullptr;
    Artist *a2 = nullptr;
    for (auto &artist : graph.nodes)
    {
        if (artist.name == artist1)
        {
            a1 = &artist;
        }
        if (artist.name == artist2)
        {
            a2 = &artist;
        }
    }
    // Add the collaboration to the list of edges for both artists
    a1->collaborations.push_back({artist2, weight});
    a2->collaborations.push_back({artist1, weight});
    graph.num_edges++;
}

// Implement a function to find the collaborations between two artists
std::list<std::pair<std::string, int>> findCollaborations(const MultiGraph &graph, const std::string &artist1, const std::string &artist2)
{
    // Find the artist objects for the two artists
    const Artist *a1 = nullptr;
    const Artist *a2 = nullptr;
    for (const auto &artist : graph.nodes)
    {
        if (artist.name == artist1)
        {
            a1 = &artist;
        }
        if (artist.name == artist2)
        {
            a2 = &artist;
        }
    }
    // Check if there are any collaborations between the two artists
    std::list<std::pair<std::string, int>> collaborations;
    for (const auto &collaboration : a1->collaborations)
    {
        if (collaboration.first == artist2)
        {
            collaborations.push_back(collaboration);
        }
    }
    return collaborations;
}