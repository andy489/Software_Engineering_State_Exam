package request;

import java.util.Objects;

public class Request {
    private final RequestType requestType;
    private final String requestDescription;
    private boolean isHandled;

    {
        isHandled = false;
    }

    public Request(final RequestType requestType, final String requestDescription) {
        this.requestType = Objects.requireNonNull(requestType);
        this.requestDescription = Objects.requireNonNull(requestDescription);
    }

    public RequestType getRequestType() {
        return requestType;
    }

    public String getRequestDescription() {
        return requestDescription;
    }

    public void markHandled() {
        isHandled = true;
    }

    @Override
    public String toString() {
        return getRequestDescription();
    }

}


