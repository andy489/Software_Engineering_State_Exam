package handler;

import request.Request;

public abstract class RequestHandler {
    private final RequestHandler next;

    public RequestHandler(RequestHandler next) {
        this.next = next;
    }

    public void handleRequest(Request req) {
        if (next != null) {
            next.handleRequest(req);
        }
    }

    protected void printHandling(Request req) {
        System.out.printf("%s handling request \"%s\"%n", this, req);
    }

    @Override
    public abstract String toString();
}
