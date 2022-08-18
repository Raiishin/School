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

    def are_there_still_customers_to_be_served(self):
        print("Checking if there are still customers to be served \n")
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]
            if pServer['status'] == "busy":
                return True
                    
            

        for i in range(len(self.secondary_server_array)):
            sServer = self.secondary_server_array[i]
            if sServer['status'] == "busy":
                return True


    def process_customer_in_primary_queue(self, primary_queue, simulated_minute):
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]
            if self.check_status(pServer) == "available" and primary_queue.size() > 0:
                customer = primary_queue.dequeue()
                wait_time = simulated_minute - customer.get_primary_arrival_time()

                customer.set_primary_queue_wait_time(wait_time)
                self.assign_customer(
                    pServer, customer, customer.get_primary_server_requirement())

                break

    def process_customer_in_secondary_queue(self, secondary_queue, simulated_minute):
        for i in range(len(self.secondary_server_array)):
            print("\n Secondary Queue",secondary_queue.size()," \n")

            sServer = self.secondary_server_array[i]
            if self.check_status(sServer) == "available" and secondary_queue.size() > 0:
                print("processing customer finish primary moving to secondary")
                customer = secondary_queue.dequeue()
                wait_time = simulated_minute - customer.get_secondary_arrival_time()

                customer.set_secondary_queue_wait_time(wait_time)
                self.assign_customer(
                    sServer, customer, customer.get_secondary_server_requirement())
                
                break

    def process_time(self, secondary_queue, simulated_minute):
        for i in range(len(self.secondary_server_array)):
            sServer = self.secondary_server_array[i]

            if sServer['status'] == "available":
                sServer['idle'] += 1
            else:
                sServer['service'] -= 1
                if sServer['service'] == 0:
                    sServer['status'] = "available"
                    sServer['customer'] = ""
                    
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]

            if pServer['status'] == "available":
                pServer['idle'] += 1
            else:
                if pServer['service'] >= 1:
                    pServer['service'] -= 1

                if pServer['service'] == 0:
                    pServer['status'] = "available"

                    # assign customer to secondary server
                    secondary_queue.enqueue(pServer['customer'])
                    self.process_customer_in_secondary_queue(
                        secondary_queue, simulated_minute)
                    
                    pServer['customer'] = ""
                    



    def check_status(self, server):
        if server['service'] > 0:
            server['status'] = "busy"
        else:
            server['status'] = "available"

        return server['status']

    def assign_customer(self, server, customer, service_time):
        server['service'] = service_time
        server['customer'] = customer
        self.check_status(server)

    def get_server_status(self):
        for i in range(len(self.primary_server_array)):
            pServer = self.primary_server_array[i]
            print(pServer)
        for i in range(len(self.secondary_server_array)):
            sServer = self.secondary_server_array[i]
            print(sServer)


class Queue:
    def __init__(self):
        self.queue = []
        self.max_size = 0
        self.total_customer_count = 0
        self.total_time_passed = 1

    def __str__(self):
        return f"Total Customers: {self.total_customer_count}, with total time spent: {self.total_time_passed}"

    def get_queue(self):
        return self.queue

    def enqueue(self, customer):
        self.queue.append(customer)
        self.total_customer_count += 1
        self.update_max_size()

    def dequeue(self):
        return self.queue.pop(0)

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
    prev = simulated_minute

    while (primary_queue.size() > 0):
        print("time:",simulated_minute)
        print(prev)

        if simulated_minute != prev:
            # If repeat, time shouldnt run again
            if simulated_minute > 1:
                primary_queue.process_time()
                secondary_queue.process_time()

            print("process")
            servers.process_time(secondary_queue, simulated_minute)
            

        prev = simulated_minute

        front_customer = primary_queue.front()

        if front_customer.get_arrival_time() == simulated_minute:
            print("time hit",front_customer)
            servers.process_customer_in_primary_queue(primary_queue, simulated_minute)
        else:
            servers.get_server_status()
            simulated_minute += 1

    # Up to here is correct
    servers.get_server_status()
    simulated_minute += 1
    
    while (servers.are_there_still_customers_to_be_served()):
        print("time:",simulated_minute)
        print(prev)

        primary_queue.process_time()
        secondary_queue.process_time()
        servers.process_time(secondary_queue, simulated_minute)

        if (secondary_queue.size() > 0):
            front_customer = secondary_queue.front()

            servers.process_customer_in_secondary_queue(secondary_queue, simulated_minute)
        
        servers.get_server_status()
        simulated_minute += 1

    print(primary_queue)
    print(secondary_queue)
    
main()
