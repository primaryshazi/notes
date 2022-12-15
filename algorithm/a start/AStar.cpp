#include "AStar.h"
#include <algorithm>
#include <math.h>

using namespace std::placeholders;

AStar::PathNode::PathNode(Vec2i coordinates_, PathNode *parent_)
{
	parent = parent_;
	coordinates = coordinates_;
	G = H = 0;
}

AStar::uint AStar::PathNode::getScore()
{
	return G + H;
}

AStar::Generator::Generator()
{
	setDiagonalMovement(false);
	setHeuristic(&Heuristic::manhattan);
	direction = {
		{ 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 },
		{ -1, -1 },{ 1, 1 },{ -1, 1 },{ 1, -1 }
	};
}

void AStar::Generator::setWorldSize(Vec2i worldSize_)
{
	worldSize = worldSize_;
}

void AStar::Generator::setDiagonalMovement(bool enable_)
{
	directions = (enable_ ? 8 : 4);
}

void AStar::Generator::setHeuristic(HeuristicFunction heuristic_)
{
	heuristic = std::bind(heuristic_, _1, _2);
}

void AStar::Generator::addCollision(Vec2i coordinates_)
{
	walls.emplace(coordinates_);
}

void AStar::Generator::removeCollision(Vec2i coordinates_)
{
	walls.erase(coordinates_);
}

void AStar::Generator::clearCollisions()
{
	walls.clear();
}

void AStar::Generator::clear()
{
	heuristic = nullptr;
	worldSize = Vec2i(0, 0);
	walls.clear();
}

AStar::CoordinateList AStar::Generator::findPath(Vec2i source_, Vec2i target_)
{
	PathNode *current = nullptr;
	NodeSet openSet, closedSet;
	openSet.emplace(new PathNode(source_));

	while (!openSet.empty()) {
		auto current_it = openSet.begin();
		current = *current_it;

		for (auto it = openSet.begin(); it != openSet.end(); it++) {
			auto node = *it;
			if (node->getScore() <= current->getScore()) {
				current = node;
				current_it = it;
			}
		}

		if (current->coordinates == target_) {
			break;
		}

		closedSet.emplace(current);
		openSet.erase(current_it);

		for (uint i = 0; i < directions; ++i) {
			Vec2i newCoordinates(current->coordinates + direction[i]);
			if (detectCollision(newCoordinates) ||
				findNodeOnList(closedSet, newCoordinates)) {
				continue;
			}

			uint totalCost = current->G + ((i < 4) ? 10 : 14);

			PathNode *successor = findNodeOnList(openSet, newCoordinates);
			if (successor == nullptr) {
				successor = new PathNode(newCoordinates, current);
				successor->G = totalCost;
				successor->H = heuristic(successor->coordinates, target_);
				openSet.emplace(successor);
			}
			else if (totalCost < successor->G) {
				successor->parent = current;
				successor->G = totalCost;
			}
		}
	}

	CoordinateList path;
	while (current != nullptr) {
		path.push_back(current->coordinates);
		current = current->parent;
	}

	releaseNodes(openSet);
	releaseNodes(closedSet);

	return path;
}

AStar::PathNode *AStar::Generator::findNodeOnList(NodeSet &nodes_, Vec2i coordinates_)
{
	auto n = PathNode(coordinates_);
	auto it = nodes_.find(&n);
	if (it != nodes_.end())
	{
		return *it;
	}
	return nullptr;
}

void AStar::Generator::releaseNodes(NodeSet &nodes_)
{
	for (auto it = nodes_.begin(); it != nodes_.end();) {
		delete *it;
		it = nodes_.erase(it);
	}
}

bool AStar::Generator::detectCollision(Vec2i coordinates_)
{
	if (coordinates_.x < 0 || coordinates_.x >= worldSize.x ||
		coordinates_.y < 0 || coordinates_.y >= worldSize.y ||
		walls.find(coordinates_) != walls.end()) {
		return true;
	}
	return false;
}

AStar::Vec2i AStar::Heuristic::getDelta(Vec2i source_, Vec2i target_)
{
	return{ abs(source_.x - target_.x),  abs(source_.y - target_.y) };
}

AStar::uint AStar::Heuristic::manhattan(Vec2i source_, Vec2i target_)
{
	auto delta = std::move(getDelta(source_, target_));
	return static_cast<uint>(10 * (delta.x + delta.y));
}

AStar::uint AStar::Heuristic::euclidean(Vec2i source_, Vec2i target_)
{
	auto delta = std::move(getDelta(source_, target_));
	return static_cast<uint>(10 * sqrt(pow(delta.x, 2) + pow(delta.y, 2)));
}

AStar::uint AStar::Heuristic::octagonal(Vec2i source_, Vec2i target_)
{
	auto delta = std::move(getDelta(source_, target_));
	return 10 * (delta.x + delta.y) + (-6) * std::min(delta.x, delta.y);
}
