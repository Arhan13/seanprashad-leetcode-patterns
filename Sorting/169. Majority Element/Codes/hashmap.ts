function majorityElement(nums: number[]): number {
  const _map = new Map<number, number>();
  nums.forEach((num) => {
    if (!_map.get(num)) {
      _map.set(num, 1);
    } else {
      const counter = _map.get(num);
      if (counter > nums.length / 2) {
        return num;
      }
      _map.set(num, counter + 1);
    }
  });
  return [..._map.entries()].reduce((a, e) => (a[1] > e[1] ? a : e))[0];
}
