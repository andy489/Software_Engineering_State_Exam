package com.fmi.state.exam;

public class Laptop {
    private static int connectedCount = 0;

    private Boolean isConnected;
    private Integer gigaByte;
    private Integer processorsCount;
    private Float gigaHertz;

    public Laptop() {
        isConnected = false;
        gigaByte = null;
        processorsCount = null;
        gigaHertz = null;
    }

    public Laptop(Boolean isConnected, Integer gigaByte, Integer processorsCount, Float gigaHertz) {
        if (isConnected) {
            connectedCount++;
        }

        this.isConnected = isConnected;
        this.gigaByte = gigaByte;
        this.processorsCount = processorsCount;
        this.gigaHertz = gigaHertz;
    }

    public Laptop(Laptop other) { // shallow copy
        if (other.isConnected) {
            connectedCount++;
        }

        isConnected = other.isConnected;
        gigaByte = other.gigaByte;
        processorsCount = other.processorsCount;
        gigaHertz = other.gigaHertz;
    }

    public static Integer getAllConnected(){
        return connectedCount;
    }

    public Boolean getConnected() {
        return isConnected;
    }

    public void setIsConnected(Boolean isConnected) {
        if (isConnected && !this.isConnected) {
            connectedCount++;
        }

        if (!isConnected && this.isConnected) {
            connectedCount--;
        }

        this.isConnected = isConnected;
    }

    public Integer getGigaByte() {
        return gigaByte;
    }

    public void setGigaByte(Integer gigaByte) {
        this.gigaByte = gigaByte;
    }

    public Integer getProcessorsCount() {
        return processorsCount;
    }

    public void setProcessorsCount(Integer processorsCount) {
        this.processorsCount = processorsCount;
    }

    public Float getGigaHertz() {
        return gigaHertz;
    }

    public void setGigaHertz(Float gigaHertz) {
        this.gigaHertz = gigaHertz;
    }
}
