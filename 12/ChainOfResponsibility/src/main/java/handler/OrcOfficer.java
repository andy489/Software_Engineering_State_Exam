package handler;

import request.Request;
import request.RequestType;

public class OrcOfficer extends RequestHandler {

    public OrcOfficer(RequestHandler handler) {
        super(handler);
    }

    public void handleRequest(Request req) {
        if (RequestType.TORTURE_PRISONER.equals(req.getRequestType())) {
            printHandling(req);
            req.markHandled();
        } else {
            super.handleRequest(req);
        }
    }

    @Override
    public String toString() {
        return "Ork officer";
    }
}
