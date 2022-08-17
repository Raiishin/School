import fileinput


class Customer:
    def __init__(self, arrival_time, primary_server_requirement, secondary_server_requirement):
        self.arrival_time = arrival_time
        self.primary_server_requirement = primary_server_requirement
        self.secondary_server_requirement = secondary_server_requirement

    def __str__(self):
        return f"{self.arrival_time}: {self.primary_server_requirement} & {self.secondary_server_requirement}"

    def get_arrival_time(self):
        return self.arrival_time

    def get_primary_service_time(self):
        return self.primary_server_requirement

    def get_secondary_service_time(self):
        return self.secondary_server_requirement

    def serve(server):
        server.serve()


class Server:
    def __init__(self):
        self.service_time = 0
        self.get_status()

    def __str__(self):
        if (self.get_status() == "available"):
            return f"{self.status}"
        else:
            return f"{self.status}: {self.service_time}"

    def get_status(self):
        self.status = "available"

        if self.service_time > 0:
            self.status = "busy"

        return self.status

    def serve(self, customer, service_time):
        self.customer = customer
        self.status = "busy"
        self.service_time = service_time

    def process_simulated_minute(self):
        self.service_time -= 1
        self.get_status()

    def finish_service(self):
        self.status = "available"
        self.service_time = 0


def enqueue(queue, item):
    return queue.append(item)


def dequeue(queue, item):
    for i in range(len(queue)):
        if queue[i] == item:
            return queue.pop(i)


def front(queue):
    return queue[0]


def rear(queue):
    return queue[len(queue) - 1]


def main():
    # Init Queue
    queue = []
    primary_servers = []
    secondary_servers = []

    for line in fileinput.input():

        str = line.rstrip()
        splitted = str.split(" ")

        print(splitted)

        if len(splitted) == 2:
            for i in range(int(splitted[0])):
                primary_servers.append(Server())

            for i in range(int(splitted[1])):
                secondary_servers.append(Server())

            # print(primary_servers[0])

            # primary_servers[0].serve(3)
            # primary_servers[0].process_simulated_minute()

            # print(primary_servers[0])

            # print(secondary_servers)

        if len(splitted) == 3:
            if splitted[0] == "0":
                break

            new_customer = Customer(int(splitted[0]), int(
                splitted[1]), int(splitted[2]))
            enqueue(queue, new_customer)

    # Need 2 queues ( primary + secondary )
    primary_queue = []
    secondary_queue = []

    simulated_minute = 1

    while len(queue) >= 0:
        # Process time passing for each server
        if (simulated_minute > 1):
            for i in range(len(primary_servers)):
                print(primary_servers[i].get_status())
                if primary_servers[i].get_status() == "busy":
                    primary_servers[i].process_simulated_minute()

        # Start simulated_minute 1, check if there is a customer coming in
        is_there_a_customer = False

        for i in range(len(queue)):
            if queue[i].get_arrival_time() == simulated_minute:
                print(queue[i])
                customer = front(queue)

                is_there_a_customer = True

        if is_there_a_customer:
            # check if there is a primary server ready to serve
            if (len(primary_servers)) > 0:
                primary_servers[0].serve(
                    customer, customer.get_primary_service_time())

                # If so, process the customer into the primary queue
                enqueue(primary_queue, customer)

                print("hi")

            # if so, assign and the customer and pop the customer out of the primary queue
            # when the customer's primary service time is done, enqueue into secondary queue and repeat
            # once customer is done with secondary queue, pop and enqueue into served_array from queue and secondary queue

            # If there is a customer but no servers available, we will let the customer wait but we need to track the waiting time (attribute in Customer class)

        if (len(queue) <= 0):
            break

        simulated_minute += 1


main()
