import fileinput


class Customer:
    primary_arrival_time = 0
    primary_queue_wait_time = 0

    secondary_arrival_time = 0
    secondary_queue_wait_time = 0

    def __init__(self, arrival_time, primary_server_requirement, secondary_server_requirement):
        self.arrival_time = arrival_time
        self.primary_server_requirement = primary_server_requirement
        self.secondary_server_requirement = secondary_server_requirement

    def __str__(self):
        return f"{self.arrival_time} : {self.primary_server_requirement}, {self.secondary_server_requirement}"

    def get_arrival_time(self):
        return self.arrival_time

    def set_primary_arrival_time(self, arrival_time):
        self.primary_arrival_time = arrival_time

    def get_primary_arrival_time(self):
        return self.primary_arrival_time

    def get_primary_server_requirement(self):
        return self.primary_server_requirement

    def set_primary_queue_wait_time(self, wait_time):
        self.primary_queue_wait_time = wait_time

    def set_secondary_arrival_time(self, arrival_time):
        self.secondary_arrival_time = arrival_time

    def get_secondary_arrival_time(self):
        return self.secondary_arrival_time

    def get_secondary_server_requirement(self):
        return self.secondary_server_requirement

    def set_secondary_queue_wait_time(self, wait_time):
        self.secondary_queue_wait_time = wait_time


class Servers:
    primary_server_array = []
    secondary_server_array = []

    def __init__(self, primary_servers, secondary_servers):
        for i in range(int(primary_servers)):
            self.primary_server_array.append(
                {"id": i, "status": "available", "idle": 0, "service": 0})

        for i in range(int(secondary_servers)):
            self.secondary_server_array.append(
                {"id": i, "status": "available", "idle": 0, "service": 0})

    def __str__(self):
        return f"{self.primary_server_array}"

    def process_customer_in_primary_queue(self, primary_queue, customer, simulated_minute):
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]
            if self.check_status(pServer) == "available" and primary_queue.size() > 0:
                customer = primary_queue.dequeue()
                wait_time = simulated_minute - customer.get_primary_arrival_time()

                customer.set_primary_queue_wait_time(wait_time)
                self.assign_customer(
                    pServer, customer, customer.get_primary_server_requirement())

    def process_customer_in_secondary_queue(self, secondary_queue, customer, simulated_minute):
        for i in range(len(self.secondary_server_array)):
            sServer = self.secondary_server_array[i]
            if self.check_status(sServer) == "available" and secondary_queue.size() > 0:
                customer = secondary_queue.dequeue()
                wait_time = simulated_minute - customer.get_secondary_arrival_time()

                customer.set_secondary_queue_wait_time(wait_time)
                self.assign_customer(
                    sServer, customer, customer.get_secondary_server_requirement())

    def process_time(self, secondary_queue, simulated_minute):
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]
            if pServer['status'] == "available":
                pServer['idle'] += 1
            else:
                if pServer['service'] >= 1:
                    pServer['service'] -= 1

                if pServer['service'] == 0:
                    # assign customer to secondary server
                    self.process_customer_in_secondary_queue(
                        secondary_queue, pServer['customer'], simulated_minute)

        for i in range(len(self.secondary_server_array)):
            sServer = self.secondary_server_array[i]
            if sServer['status'] == "available":
                sServer['idle'] += 1
            else:
                sServer['service'] -= 1
                if sServer['service'] == 0:
                    # pop customer
                    secondary_queue.dequeue()

    def check_status(self, server):
        if server['service'] > 0:
            server['status'] = "busy"
        else:
            server['status'] = "available"

        return server['status']

    def assign_customer(self, server, customer, service_time):
        print(customer)
        server['service'] = service_time
        server['customer'] = customer
        self.check_status(server)


class Queue:
    def __init__(self):
        self.queue = []
        self.max_size = 0
        self.total_customer_count = 0
        self.total_time_passed = 0

    def __str__(self):
        return f"{self.total_customer_count}"

    def get_queue(self):
        return self.queue

    def enqueue(self, customer):
        self.queue.append(customer)
        self.total_customer_count += 1
        self.update_max_size()

    def dequeue(self):
        return self.queue.pop()

    def update_max_size(self):
        if self.size() > self.max_size:
            self.max_size = self.size()

    def size(self):
        return len(self.queue)

    def process_time(self):
        self.total_time_passed += 1

    def front(self):
        return self.queue[0]


def main():
    primary_queue = Queue()
    secondary_queue = Queue()

    for line in fileinput.input():
        str = line.rstrip()
        splitted = str.split(" ")

        # Initialize servers
        if len(splitted) == 2:
            servers = Servers(splitted[0], splitted[1])

        if len(splitted) == 3:
            arrival_time = int(splitted[0])
            primary_server_requirement = int(splitted[1])
            secondary_server_requirement = int(splitted[2])

            if arrival_time == 0:
                break

            # Initialize new customer
            customer = Customer(
                arrival_time, primary_server_requirement, secondary_server_requirement)

            # Queue customer
            primary_queue.enqueue(customer)

    simulated_minute = 1

    while (primary_queue.size() > 0 and simulated_minute < 10):
        for i in range(primary_queue.size()):
            print("Customer:", primary_queue.get_queue()[i])

        front_customer = primary_queue.front()
        # print(front_customer, simulated_minute)
        # print("size: ", primary_queue.size())
        if front_customer.get_arrival_time() == simulated_minute:
            print("hello")
            servers.process_customer_in_primary_queue(
                primary_queue, customer, simulated_minute)

        servers.process_time(secondary_queue, simulated_minute)

        simulated_minute += 1


main()
