// include the header file
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../grap.h/graph.h"

// using namespace
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// test class
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
        public:
        // test method
        TEST_METHOD(insertEgde)
        {
            Graph* graph = new Graph();
            graph->newNode(0);
            graph->newNode(1);
            Assert::IsTrue(!graph->isPath(graph, graph->returnNode(0), graph->returnNode(1)));
            graph->newEdges(graph->returnNode(0), graph->returnNode(1), 3);
            Assert::IsTrue(graph->isPath(graph, graph->returnNode(0), graph->returnNode(1))); 
        }

        TEST_METHOD(insertNode)
        {
            Graph* graph = new Graph();
            Assert::IsTrue(graph->returnNode(1), == nullptr); //test the node doesnt already exist
            graph->newNode(1);
            Assert::IsTrue(graph->returnNode(1) != nullptr); //check it doesnt = 0 so it knows the node exists
        }

        TEST_METHOD(dijkstraTestConnectedNode)
        {
            int corAns;
            Graph* graph = new Graph();
            graph->newNode(1);
            graph->newNode(2);
            graph->newNode(3);
            graph->newNode(4);
            graph->newNode(5);
            graph->newNode(6);
            graph->newNode(7);
            graph->newNode(8); //this node has no connection
            graph->newEdges(graph->returnNode(0), graph->returnNode(1), 3);
            graph->newEdges(graph->returnNode(2), graph->returnNode(0), 2);
            graph->newEdges(graph->returnNode(2), graph->returnNode(1), 3);
            graph->newEdges(graph->returnNode(5), graph->returnNode(6), 1);
            graph->newEdges(graph->returnNode(2), graph->returnNode(6), 2);
            graph->newEdges(graph->returnNode(1), graph->returnNode(7), 3);
            graph->newEdges(graph->returnNode(0), graph->returnNode(5), 3);
            graph->newEdges(graph->returnNode(3), graph->returnNode(5), 4);
            graph->newEdges(graph->returnNode(4), graph->returnNode(7), 2);
            graph->newEdges(graph->returnNode(6), graph->returnNode(3), 1);

            corAns = 3;
            Assert::IsTrue(graph->dijkstra(graph, graph->returnNode(0), graph->returnNode(1)) == corAns);
        } 
    }
}