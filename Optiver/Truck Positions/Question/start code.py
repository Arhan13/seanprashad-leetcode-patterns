from dataclasses import dataclass, replace

@dataclass
class TruckPosition:
	x: float
	y: float

@dataclass
class TruckPositionDelta:
	truck_id: int
	delta_x: float
	delta_y: float

class Subscriber:
	def __init__(self, server):
		pass
	def process_update(self, update):
		pass
	def subscribe_to_truck(self, truck_id, client_id):
		return TruckPosition(0, 0)
	def get_updates(self, client_id):
		return [TruckPositionDelta(0, 0, 0)]
		
class Server:
	def __init__(self):
		self.registered_trucks = set()
		self.current_pos = {}
		
	def subscribe_to_truck(self, truck_id):
		self.registered_trucks.add(truck_id)
		return replace(self.current_pos([truck_id])
		
	def add_position(self, truck_id, pos):
		self.current_pos[truck_id] = pos