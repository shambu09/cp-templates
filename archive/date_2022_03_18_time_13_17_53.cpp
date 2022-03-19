class HashMap {
	vector<list<pair<int, int>>> container;
	const int size = 1e4 + 5;
	const int mult = 1e9 + 7;

  public:
	HashMap() { container.resize(size); }

	int hash(int key) {
		key = (int)((1ll * key * mult) % size);
		return key;
	}

	void put(int key, int value) {
		remove(key);
		int h = hash(key);
		container[h].push_back({key, value});
	}

	int get(int key) {
		int h = hash(key);
		auto iter =
			find_if(container[h].begin(), container[h].end(),
					[&key](pair<int, int> node) { return node.first == key; });
		if(iter != container[h].end())
			return iter->second;
		else
			return -1;
	}

	void remove(int key) {
		int h = hash(key);
		container[h].remove_if(
			[&key](pair<int, int> node) { return node.first == key; });
	}
};
