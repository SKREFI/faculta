class UndergroundSystem:

    def __init__(self):
        self.logs = []  # id, start station, end station, time
        self.d = {}  # id --> (start, stop, time)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        # a customer with id gets in the station stationName at time t
        # can be only checked into one place at a a time
        event = [id, stationName, None, t]
        self.logs.append(event)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        # id gets out of station at stationName at time t
        for l in self.logs:
            if l[0] == id and l[2] == None:
                l[2] = stationName
                l[3] = t - l[3]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        # avarage time to travel from startStation to endStation
        times = []
        for l in self.logs:
            if l[1] == startStation and l[2] == endStation:
                times.append(l[3])
        return sum(times)/len(times)


if __name__ == "__main__":
    #  Your UndergroundSystem object will be instantiated and called as such:

    obj = UndergroundSystem()
    obj.checkIn(45, "Leyton", 3)
    obj.checkOut(45, "Waterloo", 15)
    obj.checkIn(23, "Leyton", 4)
    obj.checkOut(23, "Waterloo", 14)
    param_3 = obj.getAverageTime("Leyton", "Waterloo")
    print(param_3)
    # 1395 Count number of teams
