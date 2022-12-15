/*
Copyright (c) 2015, Damian Barczynski <daan.net@wp.eu>
Following tool is licensed under the terms and conditions of the ISC license.
For more information visit https://opensource.org/licenses/ISC.
*/
#ifndef __ASTAR_HPP_8F637DB91972F6C878D41D63F7E7214F__
#define __ASTAR_HPP_8F637DB91972F6C878D41D63F7E7214F__

#include <vector>
#include <functional>
#include <set>

namespace AStar
{
	struct Vec2i
	{
		int x = 0;
		int y = 0;

		Vec2i() {}
		Vec2i(int x_, int y_) : x(x_), y(y_) {}
		Vec2i(const Vec2i &v) : x(v.x), y(v.y) {}
		Vec2i &operator=(const Vec2i &v) {
			x = v.x; y = v.y; return *this;
		}
		~Vec2i() {}

		friend bool operator==(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return (a.x == b.x && a.y == b.y);
		}

		friend bool operator!=(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return (a.x != b.x || a.y != b.y);
		}

		friend bool operator >(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			if (a.x > b.x) {
				return true;
			}
			if (a.x < b.x) {
				return false;
			}
			return a.y > b.y;
		}

		friend bool operator <(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			if (a.x < b.x) {
				return true;
			}
			if (a.x > b.x) {
				return false;
			}
			return a.y < b.y;
		}

		friend bool operator>=(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return !(a < b);
		}

		friend bool operator<=(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return !(a > b);
		}

		friend AStar::Vec2i operator +(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return{ a.x + b.x, a.y + b.y };
		}

		friend AStar::Vec2i operator -(const AStar::Vec2i &a, const AStar::Vec2i &b) {
			return{ a.x - b.x, a.y - b.y };
		}
	};

	using uint = unsigned int;
	using HeuristicFunction = std::function<uint(Vec2i, Vec2i)>;
	using CoordinateList = std::vector<Vec2i>;
	using CoordinateSet = std::set<Vec2i>;

	struct PathNode
	{
		uint G = 0;
		uint H = 0;
		Vec2i coordinates;
		PathNode *parent = nullptr;

		PathNode(Vec2i coord_, PathNode *parent_ = nullptr);
		uint getScore();

		friend bool operator==(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates == b.coordinates;
		}

		friend bool operator!=(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates != b.coordinates;
		}

		friend bool operator >(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates > b.coordinates;
		}

		friend bool operator <(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates < b.coordinates;
		}

		friend bool operator<=(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates <= b.coordinates;
		}

		friend bool operator>=(const AStar::PathNode &a, const AStar::PathNode &b) {
			return a.coordinates >= b.coordinates;
		}

		struct PathNodeComp
		{
			bool operator() (const PathNode *na, const PathNode *nb) const
			{
				if (nullptr == na && nb == nullptr)
				{
					return false;
				}

				if (nullptr == na)
				{
					return true;
				}

				if (nullptr == nb)
				{
					return false;
				}

				return *na < *nb;
			}
		};
	};

	using NodeSet = std::set<PathNode *, PathNode::PathNodeComp>;


	class Generator
	{
		bool detectCollision(Vec2i coordinates_);
		PathNode *findNodeOnList(NodeSet &nodes_, Vec2i coordinates_);
		void releaseNodes(NodeSet &nodes_);

	public:
		Generator();
		void setWorldSize(Vec2i worldSize_);
		void setDiagonalMovement(bool enable_);
		void setHeuristic(HeuristicFunction heuristic_);
		CoordinateList findPath(Vec2i source_, Vec2i target_);
		void addCollision(Vec2i coordinates_);
		void removeCollision(Vec2i coordinates_);
		void clearCollisions();
		void clear();

	private:
		HeuristicFunction heuristic;
		CoordinateList direction;
		CoordinateSet walls;
		Vec2i worldSize;
		uint directions;
	};

	class Heuristic
	{
		static Vec2i getDelta(Vec2i source_, Vec2i target_);

	public:
		static uint manhattan(Vec2i source_, Vec2i target_);
		static uint euclidean(Vec2i source_, Vec2i target_);
		static uint octagonal(Vec2i source_, Vec2i target_);
	};
}

#endif // __ASTAR_HPP_8F637DB91972F6C878D41D63F7E7214F__
