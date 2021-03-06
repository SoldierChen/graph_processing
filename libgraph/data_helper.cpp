#include <stdio.h>

#include "host_graph_sw.h"

Graph* createGraph(const std::string &gName, const std::string &mode) {
    Graph* gptr;
    std::string dir;
    if (mode == "harp") dir = "/upb/departments/pc2/groups/harp2/x/xchen/bdw_fpga_design/bin/";
    else if (mode == "sim") dir = "/home/xinyuc/Dataset/graphs/";
    else if (mode == "rmat") dir = "/home/xinyuc/Dataset/krongen/";
    else if (mode == "de5_rmat") dir = "/home/xinyu/Dataset/krongen/";
    else if (mode == "de5_run") dir = "/home/tanhs/Data/";

    else {
        std::cout << "unknown execution environment." << std::endl;
        exit(0);
    }

    if (gName == "dblp") {
        gptr = new Graph(dir + "dblp.ungraph.txt");
    }
    else if (gName == "youtube") {
        gptr = new Graph(dir + "youtube.ungraph.txt");
    }
    else if (gName == "lj") {
        gptr = new Graph(dir + "lj.ungraph.txt");
    }
    else if (gName == "pokec") {
        gptr = new Graph(dir + "pokec-relationships.txt");
    }
    else if (gName == "wiki-talk") {
        gptr = new Graph(dir + "wiki-Talk.txt");
    }
    else if (gName == "lj1") {
        gptr = new Graph(dir + "LiveJournal1.txt");
    }
    else if (gName == "rmat-21-32") {
        gptr = new Graph(dir + "rmat-21-32.txt");
    }
    else if (gName == "rmat-19-32") {
        gptr = new Graph(dir + "rmat-19-32.txt");
    }
    else if (gName == "rmat-21-128") {
        gptr = new Graph(dir + "rmat-21-128.txt");
    }
    else if (gName == "twitter") {
        gptr = new Graph(dir + "twitter_rv.txt");
    }
    else if (gName == "friendster") {
        gptr = new Graph(dir + "friendster.ungraph.txt");
    }
    else if (gName == "example") {
        gptr = new Graph(dir + "rmat-1k-10k.txt");
    }
    else if (gName == "rmat-12-4") {
        gptr = new Graph(dir + "rmat-12-4.txt");
    }
    else if (gName == "rmat-23-4") {
        gptr = new Graph(dir + "rmat-23-4.txt");
    }
    else if (gName == "rmat-23-16") {
        gptr = new Graph(dir + "rmat-23-16.txt");
    }
    else if (gName == "wiki-Talk") {
        gptr = new Graph(dir + "soc-wiki-Talk-dir.mtx");
    }
    else if (gName == "orkut") {
        gptr = new Graph(dir + "soc-orkut-dir.edges");
    }
    else if (gName == "twitter-higgs") {
        gptr = new Graph(dir + "soc-twitter-higgs.edges");
    }
    else if (gName == "twitter-2010") {
        gptr = new Graph(dir + "soc-twitter-2010.mtx");
    }
    else if (gName == "google") {
        gptr = new Graph(dir + "web-Google.mtx");
    }
    else if (gName == "mouse-gene") {
        gptr = new Graph(dir + "bio-mouse-gene.edges");
    }
    else if (gName == "flixster") {
        gptr = new Graph(dir + "soc-flixster.mtx");
    }
    else if (gName == "rmat-24-16") {
        gptr = new Graph(dir +  "rmat-24-16.txt");
    }
    else {
        gptr = new Graph(dir +  gName);
    }

    return gptr;
}